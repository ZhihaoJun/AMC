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
        static const uint32_t ALIGN_BYTES = 4U;

        static const uint REGISTER_ZERO = 0;
        static const uint REGISTER_V0 = 2;
        static const uint REGISTER_A0 = 4;
        static const uint REGISTER_T0 = 8;
        static const uint REGISTER_GP = 28;
        static const uint REGISTER_SP = 29;

        CPU(uint32_t t_pc, uint64_t t_sp, uint64_t t_gp, RAM &t_ram);
        ~CPU();

        void tick();
        uint64_t readRegister(int id) const;
        uint32_t pc() const;
        uint32_t npc() const;
        uint32_t hi() const;
        uint32_t lo() const;

    private:
        uint64_t *m_registers;
        uint32_t m_pc;
        uint32_t m_npc;
        uint32_t m_hi;
        uint32_t m_lo;
        RAM &m_ram;
        InstructionParser *m_parser;

        inline void advanceCP(uint32_t offset);
        inline uint32_t getInstruction(uint32_t t_address) const;
        void execute(const MIPSInstruction &cmd);
        void terminate();
        inline uint64_t &reg(uint8_t id);
    };
}

#endif //AMC_CPU_H
