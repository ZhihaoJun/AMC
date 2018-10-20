//
// Created by January on 2018/10/20.
//

#ifndef AMC_ANDIINSTRUCTION_H
#define AMC_ANDIINSTRUCTION_H

#include <instructions/IInstruction.h>

namespace AMC {
    class ANDIInstruction : public IInstruction {
    public:
        ANDIInstruction(uint32_t t_ins);
        ANDIInstruction(uint8_t t_rs, uint8_t t_rt, uint16_t t_immediate);

        uint32_t instruction() const override;

    };
}

#endif //AMC_ANDIINSTRUCTION_H
