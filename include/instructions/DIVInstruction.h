//
// Created by January on 8/30/2018.
//

#ifndef AMC_DIVINSTRUCTION_H
#define AMC_DIVINSTRUCTION_H

#include <instructions/RInstruction.h>

namespace AMC {
    class DIVInstruction : public RInstruction {
    public:
        DIVInstruction(uint32_t t_ins);
        DIVInstruction(uint8_t t_rs, uint8_t t_rt);

        uint32_t instruction() const override;
    };
}

#endif //AMC_DIVINSTRUCTION_H
