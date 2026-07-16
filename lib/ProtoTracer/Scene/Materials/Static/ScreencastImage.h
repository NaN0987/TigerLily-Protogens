/**
 * @file ScreencastImage.h
 * @brief Defines an "ScreencastImage" material that gets actively modified with serial data 
 * from an external device.
 *
 * The `ScreencastImage` class takes serial data over the mini-usb connected to the Teensy
 * and actively modifies Image data in ram to display the serial data. This can be used to display 
 * any 255-color image/video from an external device, including another device's screen.
 *
 * @date 7/13/2026
 * @author NaN0987
 */

#pragma once

#include "Image.h"
#include "Arduino.h"
#include "../../../Assets/Textures/Static/Disconnected.h"

class ScreencastImage : public Image {

private:
    static const uint8_t width = 64;
    static const uint8_t height = 32;
    static const uint16_t frame_size = width * height;
    static const uint16_t palette_size = 256 * 3;
    static const uint16_t packet_size = 2 + frame_size + palette_size;

    uint8_t data[frame_size];
    uint8_t colors[palette_size];
    bool connected = false;
    bool isHeaderFound = false;
    elapsedMillis timeSinceFrame;

    // Puts the image in "Disconnected" mode and sets "connected" to false.
    void Disconnect();

    // Enables the image to start reading bytes from the serial bus and sets "connected" to true.
    void Connect();

public:
    /**
     * @brief Constructs an ScreencastImage object. By default, the image starts
     * in "Disconnected" mode until it detects data from an external device.
     * 
     * To connect, an external device must be running the "Screencaster.py" 
     * script to communicate with the teensy over USB.
     *
     * @param size A vector for how long and wide to make the material.
     * @param offset A vector for where to position the image.
     */
    ScreencastImage(Vector2D size, Vector2D offset);

    /**
     * @brief Manages Serial Communication and updates the image being displayed
     * if "isDisplaying" is set to true.
     * 
     * This function must be called repeatedly.
     *
     * @param isDisplaying Whether or not to update what's being displayed on the protogen.
     */
    void Update(bool isDisplaying);
};