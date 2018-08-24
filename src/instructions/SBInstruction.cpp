//
// Created by January on 8/23/2018.
//

#include "instructions/SBInstruction.h"

AMC::SBInstruction::SBInstruction(uint32_t t_ins) : IInstruction(t_ins) {}

AMC::SBInstruction::SBInstruction(uint8_t t_rs, uint8_t t_rt, uint16_t t_offset) :
    IInstruction(0x28U, t_rs, t_rt, t_offset) {}

uint32_t AMC::SBInstruction::instruction() const {
    return IInstruction::instruction();
}
