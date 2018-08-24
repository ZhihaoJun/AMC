//
// Created by January on 8/23/2018.
//

#include "instructions/SWInstruction.h"

uint32_t AMC::SWInstruction::instruction() const {
    return IInstruction::instruction();
}

AMC::SWInstruction::SWInstruction(uint32_t t_ins) : IInstruction(t_ins) {}

AMC::SWInstruction::SWInstruction(uint8_t t_rs, uint8_t t_rt, uint16_t t_offset) :
    IInstruction(0x2BU, t_rs, t_rt, t_offset) {}
