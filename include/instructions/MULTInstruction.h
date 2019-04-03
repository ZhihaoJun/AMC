//
// Created by January on 8/30/2018.
//

#ifndef AMC_MULTINSTRUCTION_H
#define AMC_MULTINSTRUCTION_H

#include <instructions/RInstruction.h>

namespace AMC {
    class MULTInstruction : public RInstruction {
    public:
        MULTInstruction(uint32_t t_ins) : RInstruction(t_ins) {}
        MULTInstruction(uint8_t t_rs, uint8_t t_rt) :
                RInstruction(0x0U, t_rs, t_rt, 0x0U, 0x0U, 0x19U) {}
    };
}

#endif //AMC_MULTINSTRUCTION_H
