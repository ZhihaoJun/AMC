//
// Created by January on 8/21/2018.
//

#ifndef AMC_CPU_H
#define AMC_CPU_H

#include <cstdint>
#include "instructions/MIPSInstruction.h"
#include "RAM.h"
#include "InstructionFactory.h"

namespace AMC {
    class CPU {
    public:
        void tick();
        uint64_t readRegister(int id) const;
        uint32_t pc() const;

    private:
        uint64_t m_registers[32];
        uint32_t m_pc;
        uint32_t m_npc;
        RAM *m_ram;
        InstructionFactory *m_factory;

        inline void advanceCP(uint32_t offset);
        inline uint32_t getInstruction(uint32_t t_address) const;
        void execute(const MIPSInstruction &cmd);
    };
}

#endif //AMC_CPU_H
