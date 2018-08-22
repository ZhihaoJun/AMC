//
// Created by January on 8/22/2018.
//

#include "../../include/instructions/SyscallInstruction.h"

AMC::SyscallInstruction::SyscallInstruction(uint32_t t_ins) : RInstruction(t_ins) {

}

AMC::SyscallInstruction::SyscallInstruction() :
    RInstruction(0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0xCU) {}

uint32_t AMC::SyscallInstruction::instruction() const {
    return RInstruction::instruction();
}
