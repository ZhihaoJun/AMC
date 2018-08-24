//
// Created by January on 8/22/2018.
//

#ifndef AMC_UTIL_H
#define AMC_UTIL_H

#include <RAM.h>
#include <string>

namespace AMC {
    class Util {
    public:
        static uint32_t loadWord(RAM &t_ram, uint64_t t_address);
        static void storeWord(RAM &t_ram, uint64_t t_address, uint32_t t_word);
        static void loadFile(RAM &t_ram, uint64_t t_address, const std::string &filepath);
        static void storeString(RAM &t_ram, uint64_t t_address, const std::string &t_str);
    };
}

#endif //AMC_UTIL_H
