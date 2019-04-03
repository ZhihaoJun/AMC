//
// Created by January on 8/21/2018.
//

#ifndef AMC_ADDINSTRUCTION_H
#define AMC_ADDINSTRUCTION_H

#include "RInstruction.h"

namespace AMC {
    class ADDInstruction : public RInstruction {
    public:
        ADDInstruction(uint8_t t_rs, uint8_t t_rt, uint8_t t_rd) :
                RInstruction(0x0U, t_rs, t_rt, t_rd, 0x0U, 0x20U) {}
        ADDInstruction(uint32_t t_ins) : RInstruction(t_ins) {}
        ~ADDInstruction() override = default;
    };
}

#endif //AMC_ADDINSTRUCTION_H
