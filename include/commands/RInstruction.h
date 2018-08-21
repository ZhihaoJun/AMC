//
// Created by January on 8/21/2018.
//

#ifndef AMC_RINSTRUCTION_H
#define AMC_RINSTRUCTION_H

#include <cstdint>
#include "MIPSInstruction.h"

namespace AMC {
    class RInstruction : MIPSInstruction {
    public:
        RInstruction(uint8_t t_opcode, uint8_t t_rs, uint8_t t_rt, uint8_t t_rd, uint8_t t_shamt, uint8_t t_funct);
        RInstruction(uint32_t t_ins);
        virtual ~RInstruction() = 0;

        uint8_t opcode() const;
        uint8_t rs() const;
        uint8_t rt() const;
        uint8_t rd() const;
        uint8_t shamt() const;
        uint8_t funct() const;
        uint32_t instruction() const override;

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
