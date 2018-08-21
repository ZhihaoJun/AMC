//
// Created by January on 8/21/2018.
//

#ifndef AMC_MIPSINSTRUCTION_H
#define AMC_MIPSINSTRUCTION_H

#include <cstdint>

namespace AMC {
    class MIPSInstruction {
        virtual ~MIPSInstruction() = 0;
        virtual uint32_t instruction() const = 0;
    };
}

#endif //AMC_MIPSINSTRUCTION_H
