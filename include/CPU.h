//
// Created by January on 8/21/2018.
//

#ifndef AMC_CPU_H
#define AMC_CPU_H

#include <cstdint>
#include "instructions/MIPSInstruction.h"
#include "RAM.h"
#include "InstructionFactory.h"
#include "InstructionParser.h"

namespace AMC {
    class CPU {
    public:
        static const uint REGISTER_ZERO = 0;
        static const uint REGISTER_V0 = 2;

        CPU(uint32_t t_pc, RAM &t_ram);
        ~CPU();

        void tick();
        uint64_t readRegister(int id) const;
        uint32_t pc() const;
        uint32_t npc() const;

    private:
        uint64_t *m_registers;
        uint32_t m_pc;
        uint32_t m_npc;
        RAM &m_ram;
        InstructionParser *m_parser;

        inline void advanceCP(uint32_t offset);
        inline uint32_t getInstruction(uint32_t t_address) const;
        void execute(const MIPSInstruction &cmd);
        void terminate();
    };
}

#endif //AMC_CPU_H
