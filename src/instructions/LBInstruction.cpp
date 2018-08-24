//
// Created by January on 8/23/2018.
//

#include "instructions/LBInstruction.h"

uint32_t AMC::LBInstruction::instruction() const {
    return IInstruction::instruction();
}

AMC::LBInstruction::LBInstruction(uint32_t t_ins) : IInstruction(t_ins) {}

AMC::LBInstruction::LBInstruction(uint8_t t_rs, uint8_t t_rt, uint16_t t_offset) :
    IInstruction(0x20U, t_rs, t_rt, t_offset) {}
