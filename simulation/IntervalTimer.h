/**
 * @file IntervalTimer.h
 * @brief Simulation for the IntervalTimer.h file when in simulation mode.
 *
 * This file uses threads to simulate the Teensy's IntervalTimer functionality.
 *
 * @date 30/10/2025
 * @author NaN0987
 */

#pragma once

// #include <thread>
// #include <chrono>
// #include <atomic>
// #include <functional>

class IntervalTimer {
private:
    // std::function<void()> callback_;
    // std::atomic<int> intervalMc_;
    // std::atomic<bool> running_ = false;
    // std::thread worker_;

public:
    IntervalTimer() {}

    // Start the repeating callback in a separate thread
    void begin(std::function<void()> callback, int microseconds) {
        // if (running_) return; 
        
        // running_ = true;
        // callback_ = callback;
        // intervalMc_ = microseconds;

        // worker_ = std::thread([this]() {
        //     while (running_) {
        //         auto start = std::chrono::steady_clock::now();

        //         callback_();
        //         auto end = std::chrono::steady_clock::now();
        //         auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        //         auto sleepTime = std::chrono::microseconds(intervalMc_) - elapsed;
        //         if (sleepTime.count() > 0)
        //             std::this_thread::sleep_for(sleepTime);
        //     }
        // });
    }

    void priority(int number) {}

    void update(int microseconds) {
        // intervalMc_ = microseconds;
    }

    // Stop the loop and join the thread
    void end() {
        // if (!running_) return;
        // running_ = false;
        // if (worker_.joinable())
        //     worker_.join();
    }

    // Destructor ensures the thread stops if not already ended
    ~IntervalTimer() {
        end();
    }
};