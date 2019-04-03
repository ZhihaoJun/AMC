//
// Created by January on 4/3/2019.
//

#ifndef AMC_XORINSTRUCTION_H
#define AMC_XORINSTRUCTION_H

#include "RInstruction.h"

namespace AMC {
    class XORInstruction : public RInstruction {
    public:
        XORInstruction(uint32_t t_ins) :
            RInstruction(t_ins) {}
        XORInstruction(uint8_t t_rs, uint8_t t_rt, uint8_t t_rd) :
            RInstruction(0x0U, t_rs, t_rt, t_rd, 0x0U, 0x26U) {}
    };
}

#endif //AMC_XORINSTRUCTION_H
