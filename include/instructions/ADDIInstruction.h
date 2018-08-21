//
// Created by January on 8/21/2018.
//

#ifndef AMC_ADDIINSTRUCTION_H
#define AMC_ADDIINSTRUCTION_H

#include <stdint-gcc.h>
#include "IInstruction.h"

namespace AMC {
    class ADDIInstruction : IInstruction {
    public:
        ADDIInstruction(uint32_t t_ins);
        ADDIInstruction(uint8_t t_rs, uint8_t t_rt, uint16_t t_immediate);
        ~ADDIInstruction() override;

        uint32_t instruction() const override;
    };
}

#endif //AMC_ADDIINSTRUCTION_H
