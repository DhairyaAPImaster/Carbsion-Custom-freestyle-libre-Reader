#include <Arduino.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <SPI.h>
#include <WiFi.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#include "config.h"
#include <PN5180ISO15693.h>

namespace {

Adafruit_ILI9341 tft(config::kTftCs, config::kTftDc, config::kTftRst);
PN5180ISO15693 nfc(config::kNfcNss, config::kNfcBusy, config::kNfcRst);

float currentGlucose = 0.0f;
float currentCarbs = 0.0f;
bool aiReady = false;
bool nfcReady = false;
uint8_t lastUid[8] = {0};
unsigned long lastSensorPoll = 0;
unsigned long lastAiPoll = 0;

void setTftMessage(const String &title, const String &value, const String &footer) {
    tft.fillScreen(ILI9341_BLACK);

    tft.setTextColor(ILI9341_WHITE);
    tft.setTextWrap(false);

    tft.setTextSize(2);
    tft.setCursor(14, 18);
    tft.print(title);

    tft.setTextSize(4);
    tft.setCursor(14, 72);
    tft.print(value);

    tft.setTextSize(2);
    tft.setCursor(14, 132);
    tft.print(footer);
}

void setUiStatus(const String &glucoseText, const String &carbsText, const String &statusText) {
    tft.fillScreen(ILI9341_BLACK);

    tft.setTextColor(ILI9341_WHITE);
    tft.setTextWrap(false);

    tft.setTextSize(2);
    tft.setCursor(12, 18);
    tft.print("Carbsion");

    tft.setCursor(12, 54);
    tft.print("Glucose");

    tft.setTextSize(4);
    tft.setCursor(12, 78);
    tft.print(glucoseText);

    tft.setTextSize(2);
    tft.setCursor(12, 140);
    tft.print("AI carbs");

    tft.setTextSize(4);
    tft.setCursor(12, 164);
    tft.print(carbsText);

    tft.setTextSize(2);
    tft.setCursor(12, 224);
    tft.print(statusText);
}

bool connectWifi() {
    if (strlen(config::kWifiSsid) == 0 || strcmp(config::kWifiSsid, "REPLACE_WIFI_SSID") == 0) {
        return false;
    }

    WiFi.mode(WIFI_STA);
    WiFi.begin(config::kWifiSsid, config::kWifiPassword);

    unsigned long start = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - start < 15000) {
        delay(250);
    }

    return WiFi.status() == WL_CONNECTED;
}

String postCarbScanPrompt(const String &prompt) {
    if (WiFi.status() != WL_CONNECTED) {
        return "no wifi";
    }

    HTTPClient http;
    WiFiClientSecure client;
    client.setInsecure();

    if (!http.begin(client, "https://ai.hackclub.com/proxy/v1/chat/completions")) {
        return "api fail";
    }

    http.addHeader("Authorization", String("Bearer ") + config::kHackClubAiKey);
    http.addHeader("Content-Type", "application/json");

    StaticJsonDocument<512> body;
    body["model"] = config::kAiModel;
    JsonArray messages = body.createNestedArray("messages");
    JsonObject message = messages.createNestedObject();
    message["role"] = "user";
    message["content"] = prompt;

    String request;
    serializeJson(body, request);

    int code = http.POST(request);
    if (code <= 0) {
        http.end();
        return "api fail";
    }

    String response = http.getString();
    http.end();

    StaticJsonDocument<2048> json;
    DeserializationError error = deserializeJson(json, response);
    if (error) {
        return "parse fail";
    }

    const char *content = json["choices"][0]["message"]["content"] | "0";
    String reply = content;
    reply.trim();
    return reply;
}

float calculateGlucose(uint16_t rawValue) {
    float glucoseMmol = (rawValue * 0.0001158f) + 0.1469f;
    return glucoseMmol * 18.0f;
}

void xorDecryptFrame(const uint8_t *input, size_t inputLength, uint8_t *output, size_t outputLength) {
    if (input == nullptr || output == nullptr) {
        return;
    }

    size_t limit = inputLength < outputLength ? inputLength : outputLength;
    size_t keyLength = sizeof(config::kLibreXorKey);
    for (size_t i = 0; i < limit; ++i) {
        output[i] = input[i] ^ config::kLibreXorKey[i % keyLength];
    }
}

bool extractLibreRawValue(const uint8_t *frame, size_t frameLength, uint16_t &rawValue) {
    if (frame == nullptr || frameLength < 6) {
        return false;
    }

    // First loose parse: treat bytes 4 and 5 as the raw sensor value.
    // Adjust this later once you confirm the exact Libre frame layout.
    rawValue = static_cast<uint16_t>(frame[4] | (static_cast<uint16_t>(frame[5]) << 8));
    return true;
}

bool readLibrePayload(uint8_t *buffer, size_t bufferLength, size_t &payloadLength, String &statusText) {
    payloadLength = 0;
    statusText = "";

    uint8_t uid[8] = {0};
    ISO15693ErrorCode rc = nfc.getInventory(uid);
    if (rc != ISO15693_EC_OK) {
        statusText = String("nfc: ") + String((int)rc);
        return false;
    }

    memcpy(lastUid, uid, sizeof(lastUid));

    uint8_t blockSize = 0;
    uint8_t numBlocks = 0;
    rc = nfc.getSystemInfo(uid, &blockSize, &numBlocks);
    if (rc != ISO15693_EC_OK) {
        statusText = String("sysinfo: ") + String((int)rc);
        return false;
    }

    if (blockSize == 0) {
        blockSize = 4;
    }

    size_t copyLength = blockSize;
    if (copyLength > bufferLength) {
        copyLength = bufferLength;
    }

    uint8_t blockBuffer[32] = {0};
    size_t blocksToRead = config::kReadableBlockCount;
    if (blocksToRead > numBlocks) {
        blocksToRead = numBlocks;
    }

    for (size_t blockNo = 0; blockNo < blocksToRead; ++blockNo) {
        uint8_t perBlock[32] = {0};
        rc = nfc.readSingleBlock(uid, static_cast<uint8_t>(blockNo), perBlock, blockSize);
        if (rc != ISO15693_EC_OK) {
            statusText = String("readblk:") + String((int)rc);
            return false;
        }

        size_t offset = blockNo * blockSize;
        if (offset >= bufferLength) {
            break;
        }

        size_t room = bufferLength - offset;
        size_t writeLength = room < copyLength ? room : copyLength;
        memcpy(buffer + offset, perBlock, writeLength);
        payloadLength = offset + writeLength;
    }

    statusText = "nfc ready";
    return payloadLength > 0;
}

bool updateGlucoseReading(String &statusText) {
    uint8_t encrypted[128] = {0};
    uint8_t decrypted[128] = {0};
    size_t payloadLength = 0;

    if (!readLibrePayload(encrypted, sizeof(encrypted), payloadLength, statusText)) {
        return false;
    }

    xorDecryptFrame(encrypted, payloadLength, decrypted, payloadLength);

    uint16_t rawValue = 0;
    if (!extractLibreRawValue(decrypted, payloadLength, rawValue)) {
        statusText = "parse fail";
        return false;
    }

    currentGlucose = calculateGlucose(rawValue);
    return true;
}

void updateCarbEstimate() {
    const String prompt =
        "Look at the meal image and return a single number for estimated carbs in grams. "
        "No explanation, only the number.";

    String reply = postCarbScanPrompt(prompt);
    currentCarbs = reply.toFloat();
    if (currentCarbs < 0.0f) {
        currentCarbs = 0.0f;
    }

    aiReady = currentCarbs > 0.0f;
}

String glucoseText() {
    if (currentGlucose <= 0.0f) {
        return "--";
    }

    return String(currentGlucose, 0) + " mg/dL";
}

String carbsText() {
    if (!aiReady) {
        return "-- g";
    }

    return String(currentCarbs, 0) + " g";
}

} // namespace

void setup() {
    Serial.begin(115200);
    delay(250);

    pinMode(config::kTftBl, OUTPUT);
    digitalWrite(config::kTftBl, HIGH);

    pinMode(config::kTftCs, OUTPUT);
    digitalWrite(config::kTftCs, HIGH);

    pinMode(config::kNfcNss, OUTPUT);
    pinMode(config::kNfcRst, OUTPUT);
    pinMode(config::kNfcBusy, INPUT);

    SPI.begin(config::kTftSck, -1, config::kTftMosi, config::kTftCs);
    tft.begin();
    tft.setRotation(1);

    setTftMessage("Carbsion", "Booting", "starting display");

    nfc.begin();
    nfc.reset();
    nfcReady = nfc.setupRF();

    bool wifiConnected = connectWifi();
    if (wifiConnected) {
        Serial.println("WiFi connected");
    } else {
        Serial.println("WiFi not connected");
    }

    setUiStatus("--", "--", nfcReady ? (wifiConnected ? "ready" : "nfc ready") : "nfc fail");
}

void loop() {
    unsigned long now = millis();
    String statusText = nfcReady ? "" : "nfc fail";

    if (now - lastSensorPoll >= config::kSensorPollMs) {
        lastSensorPoll = now;
        if (nfcReady) {
            if (updateGlucoseReading(statusText)) {
                Serial.print("Glucose: ");
                Serial.println(currentGlucose, 1);
            }
        }
    }

    if (WiFi.status() == WL_CONNECTED && now - lastAiPoll >= config::kAiPollMs) {
        lastAiPoll = now;
        updateCarbEstimate();
        Serial.print("AI carbs: ");
        Serial.println(currentCarbs, 1);
    }

    if (statusText.length() == 0) {
        statusText = WiFi.status() == WL_CONNECTED ? "online" : "offline";
    }

    setUiStatus(glucoseText(), carbsText(), statusText);
    delay(150);
}
