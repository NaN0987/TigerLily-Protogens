#include "MicrophoneFourierBase.h"


float MicrophoneFourierBase::AverageMagnitude(uint16_t binL, uint16_t binH) {
    return 0.0f;
}

bool MicrophoneFourierBase::IsInitialized() {
    return true;
}

float MicrophoneFourierBase::GetSampleRate() {
    return 8000.0f;
}

float* MicrophoneFourierBase::GetSamples() {
    static float dummy = 0.0f;
    return &dummy;

}

float* MicrophoneFourierBase::GetFourier() {
    static float dummy = 0.0f;
    return &dummy;
}

float* MicrophoneFourierBase::GetFourierFiltered() {
    static float dummy = 0.0f;
    return &dummy;
}

float MicrophoneFourierBase::GetCurrentMagnitude() {
    return 0.0f;
}