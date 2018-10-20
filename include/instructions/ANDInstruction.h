//
// Created by January on 2018/10/20.
//

#ifndef AMC_ANDINSTRUCTION_H
#define AMC_ANDINSTRUCTION_H

#include <instructions/RInstruction.h>

namespace AMC {
    class ANDInstruction : public RInstruction {
    public:
        ANDInstruction(uint32_t t_ins);
        ANDInstruction(uint8_t t_rs, uint8_t t_rt, uint8_t t_rd);
        ~ANDInstruction();

        uint32_t instruction() const override;
    };
}

#endif //AMC_ANDINSTRUCTION_H
