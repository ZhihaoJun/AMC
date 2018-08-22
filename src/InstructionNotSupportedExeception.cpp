//
// Created by January on 8/22/2018.
//

#include "InstructionNotSupportedExeception.h"

AMC::InstructionNotSupportedExeception::InstructionNotSupportedExeception(uint32_t t_ins) :
    m_ins(t_ins) {}

uint32_t AMC::InstructionNotSupportedExeception::instruction() const {
    return m_ins;
}
