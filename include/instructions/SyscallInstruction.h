//
// Created by January on 8/22/2018.
//

#ifndef AMC_SYSCALLINSTRUCTION_H
#define AMC_SYSCALLINSTRUCTION_H

#include <instructions/RInstruction.h>

namespace AMC {
    class SyscallInstruction : public RInstruction {
    public:
        SyscallInstruction(uint32_t t_ins) : RInstruction(t_ins) {}
        SyscallInstruction() : RInstruction(0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0xCU) {}
    };
}

#endif //AMC_SYSCALLINSTRUCTION_H
