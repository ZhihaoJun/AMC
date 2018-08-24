//
// Created by January on 8/24/2018.
//

#include "instructions/SUBInstruction.h"

uint32_t AMC::SUBInstruction::instruction() const {
    return RInstruction::instruction();
}

AMC::SUBInstruction::SUBInstruction(uint32_t t_ins) : RInstruction(t_ins) {}

AMC::SUBInstruction::SUBInstruction(uint8_t t_rs, uint8_t t_rt, uint8_t t_rd) :
    RInstruction(0x0U, t_rs, t_rt, t_rd, 0x0U, 0x22U) {}
