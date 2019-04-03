//
// Created by January on 8/21/2018.
//

#ifndef AMC_JINSTRUCTION_H
#define AMC_JINSTRUCTION_H

#include <cstdint>
#include "MIPSInstruction.h"

namespace AMC {
    class JInstruction : public MIPSInstruction {
    public:
        JInstruction(uint8_t t_opcode, uint32_t t_address) :
                m_opcode(t_opcode), m_address(t_address), m_ins(((t_opcode & 0x3FU) << 26U) | (t_address & 0x3FFFFFFU)) {}
        JInstruction(uint32_t t_ins) :
                m_opcode((uint8_t)((t_ins >> 26U) & 0x3FU)), m_address((t_ins) & 0x3FFFFFFU) {}
        ~JInstruction() override = default;

        inline uint8_t opcode() const {
            return m_opcode;
        }

        inline uint32_t address() const {
            return m_address;
        }

        inline uint32_t instruction() const override {
            return m_ins;
        }

    private:
        uint8_t m_opcode;
        uint32_t m_address;
        uint32_t m_ins;
    };
}

#endif //AMC_JINSTRUCTION_H
