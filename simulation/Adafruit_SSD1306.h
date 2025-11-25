
#pragma once

/**
 * @file Adafruit_SSD1306.h
 * @brief Simulation for the Adafruit_SSD1306.h file when in simulation mode.
 *
 * This file simulates the Adafruit SSD1306 OLED display library by providing dummy implementations
 * of the Adafruit_SSD1306 class and its methods.
 *
 * @date 8/11/2025
 * @author NaN0987
 */

#include <cstdint>
#include <Adafruit_GFX.h>

#define SSD1306_SWITCHCAPVCC 1

class Adafruit_SSD1306 {
    public:
    Adafruit_SSD1306(int8_t width, int8_t height, TwoWire *wire, int8_t rst_pin) {}
    
    bool begin(uint8_t switchvcc, uint8_t i2caddr) { 
        return true; 
    }

    void setFont(const GFXfont* font) {}
    void clearDisplay() {}
    void invertDisplay(bool i) {}
    void display() {}
    void drawBitmap(uint16_t x, uint16_t y, const uint8_t* bitmap, uint16_t w, uint16_t h, uint16_t color) {}
    void setTextColor(uint16_t color) {}
    void setTextSize(uint8_t s) {}
    void setCursor(int16_t x, int16_t y) {}
    void println(const String str) {}
    void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {}
    
    void getTextBounds(const String &str, int16_t x, int16_t y, int16_t *x1, int16_t *y1, uint16_t *w, uint16_t *h) {
        *x1 = x;
        *y1 = y;
        *w = str.length() * 4; // Approximate width
        *h = 4; // Approximate height
    }
};
