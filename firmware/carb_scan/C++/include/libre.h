#pragma once

#include <Arduino.h>

struct LibreReading {
    uint16_t rawValue = 0;
    float glucoseMgDl = 0.0f;
    bool valid = false;
};

float calculateGlucose(uint16_t rawValue);

void xorDecryptFrame(const uint8_t *input, size_t inputLength, uint8_t *output, size_t outputLength);

bool extractLibreRawValue(const uint8_t *frame, size_t frameLength, uint16_t &rawValue);

LibreReading makeLibreReading(uint16_t rawValue);
