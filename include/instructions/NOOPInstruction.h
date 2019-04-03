//
// Created by January on 8/21/2018.
//

#ifndef AMC_NULLINSTRUCTION_H
#define AMC_NULLINSTRUCTION_H

#include "MIPSInstruction.h"

namespace AMC {
    class NOOPInstruction : public MIPSInstruction {
    public:
        NOOPInstruction() {}
        ~NOOPInstruction() override = default;
        inline uint32_t instruction() const override {
            return 0U;
        }
    };
}

#endif //AMC_NULLINSTRUCTION_H
