#include "libre.h"

#include "config.h"

float calculateGlucose(uint16_t rawValue) {
    float glucose_mmol = (rawValue * 0.0001158f) + 0.1469f;
    float glucose_mgdl = glucose_mmol * 18.0f;
    return glucose_mgdl;
}

void xorDecryptFrame(const uint8_t *input, size_t inputLength, uint8_t *output, size_t outputLength) {
    if (input == nullptr || output == nullptr || outputLength == 0) {
        return;
    }

    const size_t limit = inputLength < outputLength ? inputLength : outputLength;
    const size_t keyLength = sizeof(config::kLibreXorKey);

    for (size_t i = 0; i < limit; ++i) {
        output[i] = input[i] ^ config::kLibreXorKey[i % keyLength];
    }
}

bool extractLibreRawValue(const uint8_t *frame, size_t frameLength, uint16_t &rawValue) {
    if (frame == nullptr || frameLength < 6) {
        return false;
    }

    // This keeps the parser simple for the first firmware pass.
    // Adjust the byte offsets once the actual Libre frame layout is locked down.
    rawValue = static_cast<uint16_t>(frame[4] | (static_cast<uint16_t>(frame[5]) << 8));
    return true;
}

LibreReading makeLibreReading(uint16_t rawValue) {
    LibreReading reading;
    reading.rawValue = rawValue;
    reading.glucoseMgDl = calculateGlucose(rawValue);
    reading.valid = true;
    return reading;
}
