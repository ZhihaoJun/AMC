//
// Created by January on 8/21/2018.
//

#include "../../include/instructions/RInstruction.h"

AMC::RInstruction::RInstruction(uint8_t t_opcode, uint8_t t_rs, uint8_t t_rt, uint8_t t_rd, uint8_t t_shamt, uint8_t t_funct) :
    m_opcode(t_opcode), m_rs(t_rs), m_rt(t_rt), m_rd(t_rd), m_shamt(t_shamt), m_funct(t_funct),
    m_ins(((t_opcode & 0x3FU) << 26U) | ((t_rs & 0x1FU) << 21U) | ((t_rt & 0x1FU) << 16U) | ((t_rd & 0x1FU) << 11U) | ((t_shamt & 0x1FU) << 6U) | (t_funct & 0x3FU)) {}

AMC::RInstruction::RInstruction(uint32_t t_ins) :
    m_opcode((uint8_t)((t_ins >> 26U) & 0x3FU)), m_rs((uint8_t)((t_ins >> 21U) & 0x1FU)),
    m_rt((uint8_t)((t_ins >> 16U) & 0x1FU)), m_rd((uint8_t)((t_ins >> 11U) & 0x1FU)),
    m_shamt((uint8_t)((t_ins >> 6U) & 0x1FU)), m_funct((uint8_t)(t_ins & 0x3FU)),
    m_ins(t_ins) {}

uint8_t AMC::RInstruction::opcode() const {
    return m_opcode;
}

uint8_t AMC::RInstruction::rs() const {
    return m_rs;
}

uint8_t AMC::RInstruction::rt() const {
    return m_rt;
}

uint8_t AMC::RInstruction::rd() const {
    return m_rd;
}

uint8_t AMC::RInstruction::shamt() const {
    return m_shamt;
}

uint8_t AMC::RInstruction::funct() const {
    return m_funct;
}

uint32_t AMC::RInstruction::instruction() const {
    return m_ins;
}

AMC::RInstruction::~RInstruction() = default;
