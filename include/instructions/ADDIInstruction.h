//
// Created by January on 8/21/2018.
//

#ifndef AMC_ADDIINSTRUCTION_H
#define AMC_ADDIINSTRUCTION_H

#include <stdint-gcc.h>
#include "IInstruction.h"

namespace AMC {
    class ADDIInstruction : public IInstruction {
    public:
        ADDIInstruction(uint32_t t_ins) : IInstruction(t_ins) {}
        ADDIInstruction(uint8_t t_rs, uint8_t t_rt, uint16_t t_immediate) :
                IInstruction(0x80U, t_rs, t_rt, t_immediate) {}
        ~ADDIInstruction() override = default;
    };
}

#endif //AMC_ADDIINSTRUCTION_H
