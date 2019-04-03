//
// Created by January on 8/30/2018.
//

#ifndef AMC_DIVINSTRUCTION_H
#define AMC_DIVINSTRUCTION_H

#include <instructions/RInstruction.h>

namespace AMC {
    class DIVInstruction : public RInstruction {
    public:
        DIVInstruction(uint32_t t_ins) : RInstruction(t_ins) {}
        DIVInstruction(uint8_t t_rs, uint8_t t_rt) :
                RInstruction(0x0U, t_rs, t_rt, 0x0U, 0x0U, 0x1BU) {}
    };
}

#endif //AMC_DIVINSTRUCTION_H
