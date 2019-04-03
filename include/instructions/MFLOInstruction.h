//
// Created by January on 8/24/2018.
//

#ifndef AMC_MFLOINSTRUCTION_H
#define AMC_MFLOINSTRUCTION_H

#include <instructions/RInstruction.h>

namespace AMC {
    class MFLOInstruction : public RInstruction {
    public:
        MFLOInstruction(uint32_t t_ins) : RInstruction(t_ins) {}
        MFLOInstruction(uint8_t t_rd) :
                RInstruction(0x0U, 0x0U, 0x0U, t_rd, 0x0U, 0x12U) {}
    };
}

#endif //AMC_MFLOINSTRUCTION_H
