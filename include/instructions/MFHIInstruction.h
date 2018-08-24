//
// Created by January on 8/24/2018.
//

#ifndef AMC_MFHIINSTRUCTION_H
#define AMC_MFHIINSTRUCTION_H

#include <instructions/RInstruction.h>

namespace AMC {
    class MFHIInstruction : public RInstruction {
    public:
        MFHIInstruction(uint32_t t_ins);
        MFHIInstruction(uint8_t t_rd);

        uint32_t instruction() const override;
    };
}

#endif //AMC_MFHIINSTRUCTION_H
