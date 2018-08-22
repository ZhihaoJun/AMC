//
// Created by January on 8/22/2018.
//

#ifndef AMC_SYSCALLINSTRUCTION_H
#define AMC_SYSCALLINSTRUCTION_H

#include <instructions/RInstruction.h>

namespace AMC {
    class SyscallInstruction : public RInstruction {
    public:
        SyscallInstruction(uint32_t t_ins);
        SyscallInstruction();

        uint32_t instruction() const override;
    };
}

#endif //AMC_SYSCALLINSTRUCTION_H
