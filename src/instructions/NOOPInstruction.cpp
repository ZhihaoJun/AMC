//
// Created by January on 8/21/2018.
//

#include <instructions/NOOPInstruction.h>

#include "instructions/NOOPInstruction.h"

AMC::NOOPInstruction::NOOPInstruction() {}

uint32_t AMC::NOOPInstruction::instruction() const {
    return 0U;
}

AMC::NOOPInstruction::~NOOPInstruction() = default;
