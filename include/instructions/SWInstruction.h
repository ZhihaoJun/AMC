//
// Created by January on 8/23/2018.
//

#ifndef AMC_SWINSTRUCTION_H
#define AMC_SWINSTRUCTION_H

#include <instructions/IInstruction.h>

namespace AMC {
    class SWInstruction : public IInstruction {
    public:
        SWInstruction(uint32_t t_ins) : IInstruction(t_ins) {}
        SWInstruction(uint8_t t_rs, uint8_t t_rt, uint16_t t_offset) :
                IInstruction(0x2BU, t_rs, t_rt, t_offset) {}
    };
}

#endif //AMC_SWINSTRUCTION_H
