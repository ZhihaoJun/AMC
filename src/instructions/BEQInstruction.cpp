//
// Created by January on 8/22/2018.
//

#include "instructions/BEQInstruction.h"

AMC::BEQInstruction::BEQInstruction(uint8_t t_rs, uint8_t t_rt, uint16_t t_offset) :
    IInstruction(0x4U, t_rs, t_rt, t_offset) {}

AMC::BEQInstruction::BEQInstruction(uint32_t t_ins) : IInstruction(t_ins) {}

uint32_t AMC::BEQInstruction::instruction() const {
    return IInstruction::instruction();
}
