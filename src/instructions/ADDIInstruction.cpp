//
// Created by January on 8/21/2018.
//

#include "../../include/instructions/ADDIInstruction.h"

AMC::ADDIInstruction::ADDIInstruction(uint32_t t_ins) : IInstruction(t_ins) {}

AMC::ADDIInstruction::ADDIInstruction(uint8_t t_rs, uint8_t t_rt, uint16_t t_immediate) :
    IInstruction(0x80U, t_rs, t_rt, t_immediate) {}

uint32_t AMC::ADDIInstruction::instruction() const {
    return IInstruction::instruction();
}

AMC::ADDIInstruction::~ADDIInstruction() = default;
