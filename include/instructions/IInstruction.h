//
// Created by January on 8/21/2018.
//

#ifndef AMC_IINSTRUCTION_H
#define AMC_IINSTRUCTION_H

#include <cstdint>
#include "MIPSInstruction.h"

namespace AMC {
    class IInstruction : public MIPSInstruction {
    public:
        IInstruction(uint8_t t_opcode, uint8_t t_rs, uint8_t t_rt, uint16_t t_immediate) :
                m_opcode(t_opcode), m_rs(t_rs), m_rt(t_rt), m_immediate(t_immediate),
                m_ins(((t_opcode & 0x3FU) << 26U) | ((t_rs & 0x1FU) << 21U) | ((t_rt & 0x1FU) << 16U) | (t_immediate & 0xFFFFU)) {}
        IInstruction(uint32_t t_ins) :
                m_opcode((uint8_t)((t_ins >> 26U) & 0x3FU)), m_rs((uint8_t)((t_ins >> 21U) & 0x1FU)),
                m_rt((uint8_t)((t_ins >> 16U) & 0x1FU)), m_immediate((uint16_t)(t_ins & 0xFFFFU)),
                m_ins(t_ins) {}
        ~IInstruction() override = default;

        inline uint8_t opcode() const {
            return m_opcode;
        }

        inline uint8_t rs() const {
            return m_rs;
        }

        inline uint8_t rt() const {
            return m_rt;
        }

        inline uint16_t immediate() const {
            return m_immediate;
        }

        inline uint32_t instruction() const override {
            return m_ins;
        }

    private:
        uint8_t m_opcode;
        uint8_t m_rs;
        uint8_t m_rt;
        uint16_t m_immediate;
        uint32_t m_ins;
    };
}

#endif //AMC_IINSTRUCTION_H
