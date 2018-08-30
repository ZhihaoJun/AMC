//
// Created by January on 8/30/2018.
//

#ifndef AMC_MULTINSTRUCTION_H
#define AMC_MULTINSTRUCTION_H

#include <instructions/RInstruction.h>

namespace AMC {
    class MULTInstruction : public RInstruction {
    public:
        MULTInstruction(uint32_t t_ins);
        MULTInstruction(uint8_t t_rs, uint8_t t_rt);

        uint32_t instruction() const override;
    };
}

#endif //AMC_MULTINSTRUCTION_H
