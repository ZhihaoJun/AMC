//
// Created by January on 8/23/2018.
//

#ifndef AMC_LWINSTRUCTION_H
#define AMC_LWINSTRUCTION_H

#include <instructions/IInstruction.h>

namespace AMC {
    class LWInstruction : public IInstruction {
    public:
        LWInstruction(uint32_t t_ins) : IInstruction(t_ins) {}
        LWInstruction(uint8_t t_rs, uint8_t t_rt, uint16_t t_offset) :
                IInstruction(0x23U, t_rs, t_rt, t_offset) {}
    };
}

#endif //AMC_LWINSTRUCTION_H
