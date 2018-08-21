//
// Created by January on 8/21/2018.
//

#include "../include/CPU.h"
#include "../include/instructions/ADDInstruction.h"
#include "../include/instructions/JumpInstruction.h"

namespace AMC {
    uint64_t CPU::readRegister(int id) const {
        return m_registers[id];
    }

    void CPU::execute(const MIPSInstruction &cmd) {
        if (typeid(cmd) == typeid(ADDInstruction)) {
            auto typed = dynamic_cast<const ADDInstruction&>(cmd);
            uint8_t dst = typed.rd();
            uint8_t src = typed.rs();
            uint8_t rt = typed.rt();
            int32_t result = (int32_t)m_registers[src] + (int32_t)m_registers[rt];
            m_registers[dst] = (uint32_t)result;
            advanceCP(4U);
        } else if (typeid(cmd) == typeid(JumpInstruction)) {
            auto typed = dynamic_cast<const JumpInstruction&>(cmd);
            uint32_t target = typed.address();
            m_pc = m_npc;
            m_npc = (m_pc & 0xF0000000U) | (target << 2U);
        }
    }

    inline void CPU::advanceCP(uint32_t offset) {
        m_pc = m_npc;
        m_npc += offset;
    }

    uint32_t CPU::pc() const {
        return m_pc;
    }

    inline uint32_t CPU::getInstruction(uint32_t t_address) const {
        auto i1 = m_ram->get(t_address);
        auto i2 = m_ram->get(t_address+1U);
        auto i3 = m_ram->get(t_address+2U);
        auto i4 = m_ram->get(t_address+3U);
        return (uint32_t)(i4 << 24U | i3 << 16U | i2 << 8U | i1);
    }

    void CPU::tick() {
        uint32_t ins = getInstruction(m_pc);
        auto instruction = m_factory->instance(ins);
        execute(*instruction);
    }
}
