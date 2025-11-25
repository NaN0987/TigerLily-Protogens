/**
 * @file MicrophoneFourierBase.h
 * @brief Provides a base class for FFT-based microphone signal processing.
 *
 * This file defines the MicrophoneFourierBase class, offering foundational functionality
 * for performing Fast Fourier Transform (FFT) on microphone input signals. It includes
 * methods for retrieving FFT results and managing microphone signal data.
 *
 * @date 22/12/2024
 * @author Coela Can't
 */

#pragma once

#include <Arduino.h> // Include for Arduino compatibility.
// #include "../../../../Utils/Filter/DerivativeFilter.h" // Include for derivative filtering.
// #include "../../../../Utils/Filter/FFTFilter.h" // Include for FFT-based filtering.
// #include "../../../../Utils/Time/TimeStep.h" // Include for time management.
// #include "../../../../Utils/Signals/FFT.h" // Include for FFT processing.

/**
 * @class MicrophoneFourierBase
 * @brief Base class for FFT-based microphone signal processing.
 *
 * The MicrophoneFourierBase class provides foundational support for microphone signal processing,
 * including FFT transformations, signal normalization, and filtering. Derived classes can extend
 * its functionality for specific applications.
 */
class MicrophoneFourierBase {
protected:
   

public:
    /**
     * @brief Calculates the average magnitude of the specified FFT bins.
     *
     * @param binL The lower bound of the bin range (inclusive).
     * @param binH The upper bound of the bin range (inclusive).
     * @return The average magnitude within the specified range.
     */
    static float AverageMagnitude(uint16_t binL, uint16_t binH);

    /**
     * @brief Checks if the microphone system is initialized.
     *
     * @return True if initialized, false otherwise.
     */
    static bool IsInitialized();

    /**
     * @brief Retrieves the current sampling rate.
     *
     * @return The sampling rate in Hz.
     */
    static float GetSampleRate();

    /**
     * @brief Retrieves the raw input samples.
     *
     * @return Pointer to the array of raw input samples.
     */
    static float* GetSamples();

    /**
     * @brief Retrieves the FFT output data.
     *
     * @return Pointer to the array of FFT output data.
     */
    static float* GetFourier();

    /**
     * @brief Retrieves the filtered FFT output data.
     *
     * @return Pointer to the array of filtered FFT output data.
     */
    static float* GetFourierFiltered();

    /**
     * @brief Retrieves the current signal magnitude.
     *
     * @return The current magnitude value.
     */
    static float GetCurrentMagnitude();
};
