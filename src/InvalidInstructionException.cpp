//
// Created by January on 8/30/2018.
//

#include "InvalidInstructionException.h"

AMC::InvalidInstructionException::InvalidInstructionException(uint32_t t_ins, InvalidType t_invalidType) :
    m_ins(t_ins), m_invalidType(t_invalidType) {}

uint32_t AMC::InvalidInstructionException::instruction() const {
    return m_ins;
}

AMC::InvalidInstructionException::InvalidType AMC::InvalidInstructionException::invalidType() const {
    return m_invalidType;
}
