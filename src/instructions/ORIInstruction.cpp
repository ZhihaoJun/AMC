//
// Created by January on 8/22/2018.
//

#include "instructions/ORIInstruction.h"

AMC::ORIInstruction::ORIInstruction(uint8_t t_rs, uint8_t t_rt, uint16_t t_immediate) :
    IInstruction(0xDU, t_rs, t_rt, t_immediate) {}

AMC::ORIInstruction::ORIInstruction(uint32_t t_ins) : IInstruction(t_ins) {}

uint32_t AMC::ORIInstruction::instruction() const {
    return IInstruction::instruction();
}
