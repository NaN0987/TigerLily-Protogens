#pragma once

class DMAChannel {
public:
    DMAChannel() {}
    void sourceBuffer(void* buf, size_t size) {}
    void destination(volatile void* dest) {}
    void transferSize(int bytes) {}
    void triggerAtHardwareEvent(int event) {}
    void enable() {}
};