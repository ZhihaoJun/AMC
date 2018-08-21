//
// Created by January on 8/21/2018.
//

#ifndef AMC_NULLINSTRUCTION_H
#define AMC_NULLINSTRUCTION_H

#include "MIPSInstruction.h"

namespace AMC {
    class NullInstruction : MIPSInstruction {
    public:
        ~NullInstruction() override {}
        uint32_t instruction() const override { return 0U; }
    };
}

#endif //AMC_NULLINSTRUCTION_H
