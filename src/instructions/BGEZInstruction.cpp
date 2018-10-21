//
// Created by January on 2018/10/21.
//

#include <instructions/BGEZInstruction.h>

#include "instructions/BGEZInstruction.h"

uint32_t AMC::BGEZInstruction::instruction() const {
    return IInstruction::instruction();
}

AMC::BGEZInstruction::BGEZInstruction(uint32_t t_ins) : IInstruction(t_ins) {

}

AMC::BGEZInstruction::BGEZInstruction(uint8_t t_rs, uint16_t t_immediate) :
    IInstruction(0x1U, t_rs, 0x1U, t_immediate) {

}

AMC::BGEZInstruction::~BGEZInstruction() = default;
