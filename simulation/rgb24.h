#pragma once
#include <cstdint>

struct rgb24 {
    uint8_t R;
    uint8_t G;
    uint8_t B;

    rgb24() : R(0), G(0), B(0) {}
    rgb24(uint8_t r, uint8_t g, uint8_t b) : R(r), G(g), B(b) {}
};