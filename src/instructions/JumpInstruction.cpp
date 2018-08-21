//
// Created by ZhihaoJun on 2018-08-22.
//

#include "../../include/instructions/JumpInstruction.h"

AMC::JumpInstruction::JumpInstruction(uint32_t t_ins) : JInstruction(t_ins) {}

uint32_t AMC::JumpInstruction::instruction() const {
    return JInstruction::instruction();
}
