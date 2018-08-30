//
// Created by January on 8/30/2018.
//

#ifndef AMC_TIMER_H
#define AMC_TIMER_H

#include <chrono>

namespace AMC {
    class Timer {
    public:
        Timer();

        long elapsedNano() const;
        double elapsedMicro() const;
        double elapsedMilli() const;
    private:
        std::chrono::high_resolution_clock::time_point m_start;
    };
}

#endif //AMC_TIMER_H
