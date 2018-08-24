//
// Created by January on 8/24/2018.
//

#ifndef AMC_MFLOINSTRUCTION_H
#define AMC_MFLOINSTRUCTION_H

#include <instructions/RInstruction.h>

namespace AMC {
    class MFLOInstruction : public RInstruction {
    public:
        MFLOInstruction(uint32_t t_ins);
        MFLOInstruction(uint8_t t_rd);

        uint32_t instruction() const override;
    };
}

#endif //AMC_MFLOINSTRUCTION_H
