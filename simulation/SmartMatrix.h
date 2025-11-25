/**
 * @file MatrixHardware_Teensy4_ShieldV5.h
 * @brief Simulation for the MatrixHardware_Teensy4_ShieldV5.h file when in simulation mode.
 *
 * This file simulates RGB matrix output for HUB75 panels by displaying the pixels in a window on the computer.
 *
 * @date 30/10/2025
 * @author NaN0987
 */

#pragma once

#include "rgb24.h"
#include <cstdint>
#include "Window_Display.h"

class Layer {
private:
Window_Display display;

public:
    Layer(int kMatrixWidth, int kMatrixHeight) : display(kMatrixWidth, kMatrixHeight){
        //if(kMatrixHeight != 0 && kMatrixWidth != 0)
        
    }
    void drawPixel(uint16_t x, uint16_t y, rgb24 color) {
        display.setPixel(x, y, color);
    }
    void swapBuffers(bool waitForVSync = true) {}
};

class Matrix {
public:
    Matrix() {}
    void addLayer(Layer* layer) {}
    void begin() {}
    void setRefreshRate(int rate) {}
    void setBrightness(uint8_t brightness) {}

};

#define SM_PANELTYPE_HUB75_32ROW_MOD16SCAN 1
#define SM_HUB75_OPTIONS_NONE 0
#define SM_BACKGROUND_OPTIONS_NONE 1
#define SM_APA102_OPTIONS_COLOR_ORDER_BGR 1

#define SMARTMATRIX_ALLOCATE_BUFFERS(matrix, kMatrixWidth, kMatrixHeight, kRefreshDepth, kDmaBufferRows, kPanelType, kMatrixOptions) \
    Matrix matrix; // Dummy assignment for simulation

#define SMARTMATRIX_APA_ALLOCATE_BUFFERS(apamatrix, kApaMatrixWidth, kApaMatrixHeight, kApaRefreshDepth, kApaDmaBufferRows, kApaPanelType, kApaMatrixOptions) \
    Matrix apamatrix; // Dummy assignment for simulation

#define SMARTMATRIX_ALLOCATE_BACKGROUND_LAYER(backgroundLayer, kMatrixWidth, kMatrixHeight, color_depth, kBackgroundLayerOptions) \
    Layer backgroundLayer(kMatrixWidth, kMatrixHeight); // Dummy assignment for simulation
