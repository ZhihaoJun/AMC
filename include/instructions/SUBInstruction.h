//
// Created by January on 8/24/2018.
//

#ifndef AMC_SUBINSTRUCTION_H
#define AMC_SUBINSTRUCTION_H

#include <instructions/RInstruction.h>

namespace AMC {
    class SUBInstruction : public RInstruction {
    public:
        SUBInstruction(uint32_t t_ins) : RInstruction(t_ins) {}
        SUBInstruction(uint8_t t_rs, uint8_t t_rt, uint8_t t_rd) :
                RInstruction(0x0U, t_rs, t_rt, t_rd, 0x0U, 0x22U) {}
    };
}

#endif //AMC_SUBINSTRUCTION_H
