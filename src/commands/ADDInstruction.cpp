//
// Created by January on 8/21/2018.
//

#include "../../include/commands/ADDInstruction.h"

uint32_t AMC::ADDInstruction::instruction() const {
    return RInstruction::instruction();
}

AMC::ADDInstruction::ADDInstruction(uint8_t t_rs, uint8_t t_rt, uint8_t t_rd) :
    RInstruction(0x0U, t_rs, t_rt, t_rd, 0x0U, 0x20U) {}

AMC::ADDInstruction::ADDInstruction(uint32_t t_ins) : RInstruction(t_ins) {}
