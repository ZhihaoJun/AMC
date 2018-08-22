//
// Created by January on 8/22/2018.
//

#ifndef AMC_BEQINSTRUCTION_H
#define AMC_BEQINSTRUCTION_H

#include <instructions/IInstruction.h>

namespace AMC {
    class BEQInstruction : public IInstruction {
    public:
        BEQInstruction(uint8_t t_rs, uint8_t t_rt, uint16_t t_offset);
        BEQInstruction(uint32_t t_ins);

        uint32_t instruction() const override;
    };
}

#endif //AMC_BEQINSTRUCTION_H
