//
// Created by January on 8/21/2018.
//

#ifndef AMC_RINSTRUCTION_H
#define AMC_RINSTRUCTION_H

#include <cstdint>
#include "MIPSInstruction.h"

namespace AMC {
    class RInstruction : public MIPSInstruction {
    public:
        RInstruction(uint8_t t_opcode, uint8_t t_rs, uint8_t t_rt, uint8_t t_rd, uint8_t t_shamt, uint8_t t_funct) :
                m_opcode(t_opcode), m_rs(t_rs), m_rt(t_rt), m_rd(t_rd), m_shamt(t_shamt), m_funct(t_funct),
                m_ins(((t_opcode & 0x3FU) << 26U) | ((t_rs & 0x1FU) << 21U) | ((t_rt & 0x1FU) << 16U) | ((t_rd & 0x1FU) << 11U) | ((t_shamt & 0x1FU) << 6U) | (t_funct & 0x3FU)) {}

        RInstruction(uint32_t t_ins) :
                m_opcode((uint8_t)((t_ins >> 26U) & 0x3FU)), m_rs((uint8_t)((t_ins >> 21U) & 0x1FU)),
                m_rt((uint8_t)((t_ins >> 16U) & 0x1FU)), m_rd((uint8_t)((t_ins >> 11U) & 0x1FU)),
                m_shamt((uint8_t)((t_ins >> 6U) & 0x1FU)), m_funct((uint8_t)(t_ins & 0x3FU)),
                m_ins(t_ins) {}
        ~RInstruction() override = default;

        inline uint8_t opcode() const {
            return m_opcode;
        }

        inline uint8_t rs() const {
            return m_rs;
        }

        inline uint8_t rt() const {
            return m_rt;
        }

        inline uint8_t rd() const {
            return m_rd;
        }

        inline uint8_t shamt() const {
            return m_shamt;
        }

        inline uint8_t funct() const {
            return m_funct;
        }

        uint32_t instruction() const override {
            return m_ins;
        }

    private:
        uint8_t m_opcode;
        uint8_t m_rs;
        uint8_t m_rt;
        uint8_t m_rd;
        uint8_t m_shamt;
        uint8_t m_funct;
        uint32_t m_ins;
    };
}

#endif //AMC_RINSTRUCTION_H
