//
// Created by January on 2018/10/20.
//

#include <instructions/ADDUInstruction.h>

#include "instructions/ADDUInstruction.h"

AMC::ADDUInstruction::ADDUInstruction(uint32_t t_ins) : RInstruction(t_ins) {}

AMC::ADDUInstruction::ADDUInstruction(uint8_t t_rs, uint8_t t_rt, uint8_t t_rd) :
    RInstruction(0x0U, t_rs, t_rt, t_rd, 0x0U, 0x24U) {}

AMC::ADDUInstruction::~ADDUInstruction() = default;

uint32_t AMC::ADDUInstruction::instruction() const {
    return RInstruction::instruction();
}
