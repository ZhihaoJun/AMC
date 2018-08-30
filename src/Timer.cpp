//
// Created by January on 8/30/2018.
//

#include "Timer.h"

AMC::Timer::Timer() :
    m_start(std::chrono::high_resolution_clock::now()) {}

long AMC::Timer::elapsedNano() const {
    std::chrono::duration<long int, std::nano> elapsed = std::chrono::high_resolution_clock::now() - m_start;
    return elapsed.count();
}

double AMC::Timer::elapsedMicro() const {
    return elapsedNano() / 1000.0;
}

double AMC::Timer::elapsedMilli() const {
    return elapsedNano() / 1000000.0;
}
