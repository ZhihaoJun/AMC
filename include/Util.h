//
// Created by January on 8/22/2018.
//

#ifndef AMC_UTIL_H
#define AMC_UTIL_H

#include <RAM.h>

namespace AMC {
    class Util {
    public:
        static uint32_t getWord(RAM &t_ram, uint64_t t_address);
        static void setWord(RAM &t_ram, uint64_t t_address, uint32_t t_word);
    };
}

#endif //AMC_UTIL_H
