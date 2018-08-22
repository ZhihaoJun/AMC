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
        IInstruction(uint8_t t_opcode, uint8_t t_rs, uint8_t t_rt, uint16_t t_immediate);
        IInstruction(uint32_t t_ins);
        ~IInstruction() override;

        uint8_t opcode() const;
        uint8_t rs() const;
        uint8_t rt() const;
        uint16_t immediate() const;
        uint32_t instruction() const override;

    private:
        uint8_t m_opcode;
        uint8_t m_rs;
        uint8_t m_rt;
        uint16_t m_immediate;
        uint32_t m_ins;
    };
}

#endif //AMC_IINSTRUCTION_H
