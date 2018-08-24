//
// Created by ZhihaoJun on 2018-08-22.
//

#include "instructions/JUMPInstruction.h"

AMC::JUMPInstruction::JUMPInstruction(uint32_t t_ins) : JInstruction(t_ins) {}

uint32_t AMC::JUMPInstruction::instruction() const {
    return JInstruction::instruction();
}
