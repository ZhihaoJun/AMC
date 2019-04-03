//
// Created by January on 8/22/2018.
//

#ifndef AMC_BEQINSTRUCTION_H
#define AMC_BEQINSTRUCTION_H

#include <instructions/IInstruction.h>

namespace AMC {
    class BEQInstruction : public IInstruction {
    public:
        BEQInstruction(uint8_t t_rs, uint8_t t_rt, uint16_t t_offset) :
                IInstruction(0x4U, t_rs, t_rt, t_offset) {}
        BEQInstruction(uint32_t t_ins) : IInstruction(t_ins) {}
        ~BEQInstruction() override = default;
    };
}

#endif //AMC_BEQINSTRUCTION_H
