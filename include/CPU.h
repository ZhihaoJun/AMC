//
// Created by January on 8/21/2018.
//

#ifndef AMC_CPU_H
#define AMC_CPU_H

#include <cstdint>
#include "commands/MIPSInstruction.h"

namespace AMC {
    class CPU {
    public:
        void execute(const MIPSInstruction &cmd);
        uint64_t readRegister(int id) const;

    private:
        uint64_t m_registers[32];
    };
}

#endif //AMC_CPU_H
