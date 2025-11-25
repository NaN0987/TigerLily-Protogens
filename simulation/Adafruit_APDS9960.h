/**
 * @file APDS9960.h
 * @brief A class for interfacing with the Adafruit APDS9960 sensor.
 *
 * This file defines the APDS9960 class, which provides functionality for detecting proximity,
 * brightness, and determining if the sensor is "booped" (close proximity detection).
 * 
 * This can be used for other sensors with the 9960 chip, but it may require modification
 * of the Adafruit source code (see @file Adafruit_APDS9960.cpp, lines 100–104) to allow for 
 * different chip IDs.
 *
 * @date 22/12/2024
 * @author Coela Can't
 */

#pragma once

#include <cstdint>

/**
 * @class APDS9960
 * @brief A class for managing the Adafruit APDS9960 sensor.
 *
 * The APDS9960 class provides methods for initializing the sensor, detecting proximity and brightness,
 * and determining if the sensor is close enough to trigger a "boop" detection.
 */
class Adafruit_APDS9960 {

public:
    Adafruit_APDS9960() {}
    
    bool begin() {
        return true;
    }

    void enableProximity(bool en) {}

    uint16_t readProximity() {
        return 100;
    }
    void enableColor() {}
    void getColorData(uint16_t* r, uint16_t* g, uint16_t* b, uint16_t* c) {
        *r = 255;
        *g = 255;
        *b = 255;
        *c = 255;
    }
};
