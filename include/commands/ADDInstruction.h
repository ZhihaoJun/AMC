//
// Created by January on 8/21/2018.
//

#ifndef AMC_ADDINSTRUCTION_H
#define AMC_ADDINSTRUCTION_H

#include "RInstruction.h"

namespace AMC {
    class ADDInstruction : RInstruction {
    public:
        ADDInstruction(uint8_t t_rs, uint8_t t_rt, uint8_t t_rd);
        ADDInstruction(uint32_t t_ins);

        uint32_t instruction() const override;
    };
}

#endif //AMC_ADDINSTRUCTION_H
