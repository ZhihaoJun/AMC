//
// Created by January on 8/23/2018.
//

#ifndef AMC_SBINSTRUCTION_H
#define AMC_SBINSTRUCTION_H

#include <instructions/IInstruction.h>

namespace AMC {
    class SBInstruction : public IInstruction {
    public:
        SBInstruction(uint32_t t_ins);
        SBInstruction(uint8_t t_rs, uint8_t t_rt, uint16_t t_offset);

        uint32_t instruction() const override;
    };
}

#endif //AMC_SBINSTRUCTION_H
