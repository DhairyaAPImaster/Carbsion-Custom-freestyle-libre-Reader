#pragma once

#include <Arduino.h>

namespace config {

constexpr char kWifiSsid[] = "REPLACE_WIFI_SSID";
constexpr char kWifiPassword[] = "REPLACE_WIFI_PASSWORD";

constexpr char kHackClubAiKey[] = "REPLACE_API_KEY";
constexpr char kAiModel[] = "qwen/qwen3-32b";

// PN5180 wiring for ESP32. Keep these loose and adjust to the board later.
constexpr int kNfcNss = 16;
constexpr int kNfcBusy = 17;
constexpr int kNfcRst = 5;

// 2.8 inch SPI TFT wiring. Adjust to match your final PCB routing.
constexpr int kTftCs = 10;
constexpr int kTftDc = 9;
constexpr int kTftRst = 8;
constexpr int kTftBl = 7;
constexpr int kTftSck = 12;
constexpr int kTftMosi = 11;

// Simple repeating XOR key for the Libre1 frame helper.
constexpr uint8_t kLibreXorKey[] = {0x5A, 0xC3, 0x1F, 0x97};

constexpr unsigned long kSensorPollMs = 1500;
constexpr unsigned long kAiPollMs = 12000;
constexpr uint8_t kReadableBlockCount = 4;

} // namespace config
