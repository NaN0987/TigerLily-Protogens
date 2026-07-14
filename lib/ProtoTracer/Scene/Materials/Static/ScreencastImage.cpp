#include "ScreencastImage.h"
#include "Arduino.h"

ScreencastImage::ScreencastImage(Vector2D size, Vector2D offset) : Image(data, colors, width, height, 255) {
    for(size_t i = 0; i < frame_size; ++i) {
        data[i] = 0;
    }

    for(size_t i = 0; i < palette_size; ++i) {
        colors[i] = 0;
    }

    SetSize(size);
    SetPosition(offset);
}

void ScreencastImage::Update(bool isDisplaying) {
    int packetSize = 2 + frame_size + palette_size;

    // The while loop ensures that only the newest frame is read
    while (Serial.available() >= packetSize) {

        // Find and consume header
        if(!isHeaderFound) {
            while (Serial.available() >= 2) {
                if (Serial.read() == 0xAA) {
                    if (Serial.peek() == 0x55) {
                        Serial.read();  // Consume the 0x55
                        isHeaderFound = true;
                        break;          // Header found!
                    }
                }
            }
        }

        if (Serial.available() >= (packetSize - 2)) {
            // Read frame
            Serial.readBytes(data, frame_size);

            // Read palette
            Serial.readBytes(colors, palette_size);
            
            isHeaderFound = false;
        }
    }
}
