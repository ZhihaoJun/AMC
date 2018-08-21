//
// Created by ZhihaoJun on 2018-08-22.
//

#include "../../include/instructions/ADDIUInstruction.h"

AMC::ADDIUInstruction::ADDIUInstruction(uint32_t t_ins) : IInstruction(t_ins) {}

AMC::ADDIUInstruction::ADDIUInstruction(uint8_t t_rs, uint8_t t_rt, uint16_t t_immediate) :
    IInstruction(0x9U, t_rs, t_rt, t_immediate) {}

uint32_t AMC::ADDIUInstruction::instruction() const {
    return IInstruction::instruction();
}

AMC::ADDIUInstruction::~ADDIUInstruction() = default;
