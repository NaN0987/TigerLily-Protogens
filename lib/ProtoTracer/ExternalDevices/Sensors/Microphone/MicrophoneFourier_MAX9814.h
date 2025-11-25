/**
 * @file MicrophoneFourier_MAX9814.h
 * @brief Extends the MicrophoneFourierBase class for real-time FFT microphone analysis.
 *
 * This file defines the MicrophoneFourier class, which builds upon MicrophoneFourierBase to include
 * real-time sampling and processing of microphone signals using FFT. It incorporates utilities for
 * updating and resetting the microphone processing system.
 * 
 * For the MAX9814 microphone.
 *
 * @date 22/12/2024
 * @author Coela Can't
 */

#pragma once

#include <Arduino.h> // Include for Arduino compatibility.
// #include "../../../Utils/Filter/DerivativeFilter.h" // Include for derivative filtering.
// #include "../../../Utils/Filter/FFTFilter.h" // Include for FFT filtering.
// #include "../../../Utils/Time/TimeStep.h" // Include for time management.
#include "Utils/MicrophoneFourierBase.h" // Include the base class for microphone FFT processing.

/**
 * @class MicrophoneFourier
 * @brief Provides real-time microphone analysis using FFT.
 *
 * The MicrophoneFourier class extends MicrophoneFourierBase to add capabilities for
 * real-time sampling, signal processing, and frequency bin analysis. It enables
 * dynamic updating and resetting of the microphone system.
 */
class MicrophoneFourier : public MicrophoneFourierBase {

public:
    /**
     * @brief Initializes the microphone and FFT system.
     *
     * @param pin The pin connected to the microphone.
     * @param sampleRate The desired sampling rate in Hz.
     * @param minDB Minimum dB level for normalization.
     * @param maxDB Maximum dB level for normalization.
     * @param refreshRate The desired refresh rate for processing (default is 60 Hz).
     */
    static void Initialize(uint8_t pin, uint16_t sampleRate, float minDB, float maxDB, float refreshRate = 60.0f);

    /**
     * @brief Resets the microphone system and clears stored data.
     */
    static void Reset();

    /**
     * @brief Updates the microphone system, processing new samples and performing FFT.
     */
    static void Update();

    void StartSampler();
    void SamplerCallback();
};
