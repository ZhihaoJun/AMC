//
// Created by January on 8/30/2018.
//

#include "instructions/MULTInstruction.h"

AMC::MULTInstruction::MULTInstruction(uint32_t t_ins) : RInstruction(t_ins) {}

AMC::MULTInstruction::MULTInstruction(uint8_t t_rs, uint8_t t_rt) :
    RInstruction(0x0U, t_rs, t_rt, 0x0U, 0x0U, 0x19U) {}

uint32_t AMC::MULTInstruction::instruction() const {
    return RInstruction::instruction();
}

