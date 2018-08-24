//
// Created by January on 8/24/2018.
//

#include "instructions/MFLOInstruction.h"

uint32_t AMC::MFLOInstruction::instruction() const {
    return RInstruction::instruction();
}

AMC::MFLOInstruction::MFLOInstruction(uint32_t t_ins) : RInstruction(t_ins) {}

AMC::MFLOInstruction::MFLOInstruction(uint8_t t_rd) :
    RInstruction(0x0U, 0x0U, 0x0U, t_rd, 0x0U, 0x12U) {}
