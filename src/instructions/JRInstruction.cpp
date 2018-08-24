//
// Created by January on 8/22/2018.
//

#include "instructions/JRInstruction.h"

AMC::JRInstruction::JRInstruction(uint8_t t_rs) :
    RInstruction(0x0U, t_rs, 0x0U, 0x0U, 0x0U, 0x8U) {}

AMC::JRInstruction::JRInstruction(uint32_t t_ins) : RInstruction(t_ins) {}

uint32_t AMC::JRInstruction::instruction() const {
    return RInstruction::instruction();
}
