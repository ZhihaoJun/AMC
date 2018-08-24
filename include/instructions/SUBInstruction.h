//
// Created by January on 8/24/2018.
//

#ifndef AMC_SUBINSTRUCTION_H
#define AMC_SUBINSTRUCTION_H

#include <instructions/RInstruction.h>

namespace AMC {
    class SUBInstruction : public RInstruction {
    public:
        SUBInstruction(uint32_t t_ins);
        SUBInstruction(uint8_t t_rs, uint8_t t_rt, uint8_t t_rd);

        uint32_t instruction() const override;
    };
}

#endif //AMC_SUBINSTRUCTION_H
