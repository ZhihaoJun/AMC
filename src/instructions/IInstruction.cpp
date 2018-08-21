//
// Created by January on 8/21/2018.
//

#include "../../include/instructions/IInstruction.h"

uint16_t AMC::IInstruction::immediate() const {
    return m_immediate;
}

uint8_t AMC::IInstruction::rt() const {
    return m_rt;
}

uint8_t AMC::IInstruction::rs() const {
    return m_rs;
}

uint8_t AMC::IInstruction::opcode() const {
    return m_opcode;
}

AMC::IInstruction::IInstruction(uint8_t t_opcode, uint8_t t_rs, uint8_t t_rt, uint16_t t_immediate) :
        m_opcode(t_opcode), m_rs(t_rs), m_rt(t_rt), m_immediate(t_immediate),
        m_ins(((t_opcode & 0x3FU) << 26U) | ((t_rs & 0x1FU) << 21U) | ((t_rt & 0x1FU) << 16U) | (t_immediate & 0xFFFFU)) {}

AMC::IInstruction::IInstruction(uint32_t t_ins) :
    m_opcode((uint8_t)((t_ins >> 26U) & 0x3FU)), m_rs((uint8_t)((t_ins >> 21U) & 0x1FU)),
    m_rt((uint8_t)((t_ins >> 16U) & 0x1FU)), m_immediate((uint16_t)(t_ins & 0xFFFFU)),
    m_ins(t_ins) {}

uint32_t AMC::IInstruction::instruction() const {
    return m_ins;
}

AMC::IInstruction::~IInstruction() = default;
