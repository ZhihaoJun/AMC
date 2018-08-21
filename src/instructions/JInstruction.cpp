//
// Created by January on 8/21/2018.
//

#include "../../include/instructions/JInstruction.h"

uint8_t AMC::JInstruction::opcode() const {
    return m_opcode;
}

uint32_t AMC::JInstruction::address() const {
    return m_address;
}

AMC::JInstruction::JInstruction(uint8_t t_opcode, uint32_t t_address) :
        m_opcode(t_opcode), m_address(t_address), m_ins(((t_opcode & 0x3FU) << 26U) | (t_address & 0x3FFFFFFU)) {}

AMC::JInstruction::JInstruction(uint32_t t_ins) :
    m_opcode((uint8_t)((t_ins >> 26U) & 0x3FU)), m_address((t_ins) & 0x3FFFFFFU) {}


uint32_t AMC::JInstruction::instruction() const {
    return m_ins;
}

AMC::JInstruction::~JInstruction() = default;
