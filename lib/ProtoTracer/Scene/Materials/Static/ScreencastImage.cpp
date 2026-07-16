#include "ScreencastImage.h"

ScreencastImage::ScreencastImage(Vector2D size, Vector2D offset) 
: Image(Disconnected::rgbMemory, Disconnected::rgbColors, width, height, 255) {
    for(size_t i = 0; i < frame_size; ++i) {
        data[i] = 0;
    }

    for(size_t i = 0; i < palette_size; ++i) {
        colors[i] = 0;
    }

    SetSize(size);
    SetPosition(offset);
}

void ScreencastImage::Connect() {
    connected = true;
    SetData(data);
    SetColorPalette(colors);
}

void ScreencastImage::Disconnect() {
    connected = false;
    isHeaderFound = false;
    SetData(Disconnected::rgbMemory);
    SetColorPalette(Disconnected::rgbColors); // Big deal, may cause memory leak
}

void ScreencastImage::Update(bool isDisplaying) {
    bool bytesAvailable = Serial.available() > 1; // it's 1 because the program will always read up to 1 byte

    // Connection check: if not connected, reconnect yourself if new bytes arrived.
    // If connected, disconnect yourself if a new byte hasn't arrived for over half a second
    if (!connected) {
        if (bytesAvailable) { 
            Connect();
        }
        else {
            return;
        }
    }
    else {
        if (!bytesAvailable && timeSinceFrame > 500) {
            Disconnect();
            return;
        }
    }

    // Reset timer
    if (bytesAvailable) {
        timeSinceFrame = 0;
    }

    // If the image is not being displayed, save on cpu power by keeping the serial bus empty
    if (!isDisplaying) {
        isHeaderFound = false;

        char discard[256];
        while (Serial.available()) {
            size_t n = min((int)sizeof(discard), Serial.available());
            Serial.readBytes(discard, n);
        }
        return;
    }

    // The while loop ensures that only the newest frame is read
    while (Serial.available() >= packet_size) {

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

        // Update the image if the entire packet is loaded
        if (Serial.available() >= (packet_size - 2)) {
            // Read frame
            Serial.readBytes(reinterpret_cast<char*>(data), frame_size);

            // Read palette
            Serial.readBytes(reinterpret_cast<char*>(colors), palette_size);
            
            isHeaderFound = false;
        }
    }
}
