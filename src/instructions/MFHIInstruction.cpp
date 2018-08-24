//
// Created by January on 8/24/2018.
//

#include "instructions/MFHIInstruction.h"

uint32_t AMC::MFHIInstruction::instruction() const {
    return RInstruction::instruction();
}

AMC::MFHIInstruction::MFHIInstruction(uint32_t t_ins) : RInstruction(t_ins) {}

AMC::MFHIInstruction::MFHIInstruction(uint8_t t_rd) :
    RInstruction(0x0U, 0x0U, 0x0U, t_rd, 0x0U, 0x10U) {}
