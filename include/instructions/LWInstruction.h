//
// Created by January on 8/23/2018.
//

#ifndef AMC_LWINSTRUCTION_H
#define AMC_LWINSTRUCTION_H

#include <instructions/IInstruction.h>

namespace AMC {
    class LWInstruction : public IInstruction {
    public:
        LWInstruction(uint32_t t_ins);
        LWInstruction(uint8_t t_rs, uint8_t t_rt, uint16_t t_offset);

        uint32_t instruction() const override;
    };
}

#endif //AMC_LWINSTRUCTION_H
