//
// Created by January on 8/22/2018.
//

#include "instructions/LUIInstruction.h"

uint32_t AMC::LUIInstruction::instruction() const {
    return IInstruction::instruction();
}

AMC::LUIInstruction::LUIInstruction(uint8_t t_rt, uint16_t t_immediate) :
    IInstruction(0xFU, 0x0U, t_rt, t_immediate) {}

AMC::LUIInstruction::LUIInstruction(uint32_t t_ins) : IInstruction(t_ins) {}
