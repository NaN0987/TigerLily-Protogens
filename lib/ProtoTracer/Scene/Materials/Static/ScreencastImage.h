/**
 * @file ScreencastImage.h
 * @brief Defines an "ScreencastImage" material that gets actively modified with serial data 
 * from an external device.
 *
 * The `ScreencastImage` class takes serial data over the mini-usb connected to the teensy
 * over the ____ baud rate and actively modifies Image data in ram to display the serial data.
 * This can be used to display any 256-color image/video from an external device, including
 * another device's screen.
 *
 * @date 7/13/2026
 * @author NaN0987
 */

#pragma once

#include "Image.h"
#include "../../../Assets/Textures/Static/Frame.h"

class ScreencastImage : public Image {

private:
    static const uint8_t width = 64;
    static const uint8_t height = 32;
    static const uint16_t frame_size = width * height;
    static const uint16_t palette_size = 256 * 3;

    // Note to self: the data and colors for "Frame" are static, so I don't need to create an instance of it.
    uint8_t data[frame_size];
    uint8_t colors[palette_size];
    bool active = false;
    bool isHeaderFound = false;

public:
    /**
     * @brief Constructs an ScreencastImage object.
     *
     * @param size A vector for how long and wide to make the image.
     * @param offset A vector for where to position the image.
     */
    ScreencastImage(Vector2D size, Vector2D offset);

    void Update(bool isDisplaying);
};