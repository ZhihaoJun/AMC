//
// Created by January on 8/22/2018.
//

#ifndef AMC_LUIINSTRUCTION_H
#define AMC_LUIINSTRUCTION_H

#include <instructions/IInstruction.h>
#include <cstdint>
#include <stdint-gcc.h>

namespace AMC {
    class LUIInstruction : public IInstruction {
    public:
        LUIInstruction(uint8_t t_rt, uint16_t t_immediate);
        LUIInstruction(uint32_t t_ins);

        uint32_t instruction() const override;
    };
}

#endif //AMC_LUIINSTRUCTION_H
