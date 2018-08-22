//
// Created by January on 8/22/2018.
//

#ifndef AMC_ORIINSTRUCTION_H
#define AMC_ORIINSTRUCTION_H

#include <instructions/IInstruction.h>

namespace AMC {
    class ORIInstruction : public IInstruction {
    public:
        ORIInstruction(uint8_t t_rs, uint8_t t_rt, uint16_t t_immediate);
        ORIInstruction(uint32_t t_ins);

        uint32_t instruction() const override;
    };
}

#endif //AMC_ORIINSTRUCTION_H
