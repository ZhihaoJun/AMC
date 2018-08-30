//
// Created by January on 8/30/2018.
//

#include "instructions/DIVInstruction.h"

AMC::DIVInstruction::DIVInstruction(uint32_t t_ins) : RInstruction(t_ins) {}

AMC::DIVInstruction::DIVInstruction(uint8_t t_rs, uint8_t t_rt) :
    RInstruction(0x0U, t_rs, t_rt, 0x0U, 0x0U, 0x1BU) {}

uint32_t AMC::DIVInstruction::instruction() const {
    return RInstruction::instruction();
}
