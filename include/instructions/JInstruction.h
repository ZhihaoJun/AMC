//
// Created by January on 8/21/2018.
//

#ifndef AMC_JINSTRUCTION_H
#define AMC_JINSTRUCTION_H

#include <cstdint>
#include "MIPSInstruction.h"

namespace AMC {
    class JInstruction : MIPSInstruction {
    public:
        JInstruction(uint8_t t_opcode, uint32_t t_address);
        JInstruction(uint32_t t_ins);
        ~JInstruction() override;

        uint8_t opcode() const;
        uint32_t address() const;
        uint32_t instruction() const override;

    private:
        uint8_t m_opcode;
        uint32_t m_address;
        uint32_t m_ins;
    };
}

#endif //AMC_JINSTRUCTION_H
