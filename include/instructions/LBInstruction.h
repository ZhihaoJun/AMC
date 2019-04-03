//
// Created by January on 8/23/2018.
//

#ifndef AMC_LBINSTRUCTION_H
#define AMC_LBINSTRUCTION_H

#include <instructions/IInstruction.h>

namespace AMC {
    class LBInstruction : public IInstruction {
    public:
        LBInstruction(uint32_t t_ins) : IInstruction(t_ins) {}
        LBInstruction(uint8_t t_rs, uint8_t t_rt, uint16_t t_offset) :
                IInstruction(0x20U, t_rs, t_rt, t_offset) {}
    };
}

#endif //AMC_LBINSTRUCTION_H
