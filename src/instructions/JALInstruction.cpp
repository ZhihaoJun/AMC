//
// Created by January on 8/23/2018.
//

#include "instructions/JALInstruction.h"

AMC::JALInstruction::JALInstruction(uint32_t t_ins) : JInstruction(t_ins) {}

uint32_t AMC::JALInstruction::instruction() const {
    return JInstruction::instruction();
}
