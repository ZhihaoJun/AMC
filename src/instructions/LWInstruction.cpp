//
// Created by January on 8/23/2018.
//

#include "instructions/LWInstruction.h"

uint32_t AMC::LWInstruction::instruction() const {
    return IInstruction::instruction();
}

AMC::LWInstruction::LWInstruction(uint32_t t_ins) : IInstruction(t_ins) {}

AMC::LWInstruction::LWInstruction(uint8_t t_rs, uint8_t t_rt, uint16_t t_offset) :
    IInstruction(0x23U, t_rs, t_rt, t_offset) {}
