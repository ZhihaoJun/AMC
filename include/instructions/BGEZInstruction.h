//
// Created by January on 2018/10/21.
//

#ifndef AMC_BGEZINSTRUCTION_H
#define AMC_BGEZINSTRUCTION_H

#include "IInstruction.h"

namespace AMC {
    class BGEZInstruction : public IInstruction {
    public:
        BGEZInstruction(uint32_t t_ins);
        BGEZInstruction(uint8_t t_rs, uint16_t t_immediate);
        ~BGEZInstruction();

        uint32_t instruction() const override;
    };
}

#endif //AMC_BGEZINSTRUCTION_H
