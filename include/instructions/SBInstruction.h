//
// Created by January on 8/23/2018.
//

#ifndef AMC_SBINSTRUCTION_H
#define AMC_SBINSTRUCTION_H

#include <instructions/IInstruction.h>

namespace AMC {
    class SBInstruction : public IInstruction {
    public:
        SBInstruction(uint32_t t_ins) : IInstruction(t_ins) {}
        SBInstruction(uint8_t t_rs, uint8_t t_rt, uint16_t t_offset) :
                IInstruction(0x28U, t_rs, t_rt, t_offset) {}
    };
}

#endif //AMC_SBINSTRUCTION_H
