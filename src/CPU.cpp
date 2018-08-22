//
// Created by January on 8/21/2018.
//

#include <iostream>
#include <instructions/ORIInstruction.h>
#include <instructions/BEQInstruction.h>

#include "ProgramTerminateException.h"
#include "InstructionNotSupportedExeception.h"
#include "../include/CPU.h"
#include "../include/instructions/ADDInstruction.h"
#include "../include/instructions/JumpInstruction.h"
#include "instructions/SyscallInstruction.h"
#include "Util.h"

namespace AMC {
    uint64_t CPU::readRegister(int id) const {
        return m_registers[id];
    }

    void CPU::execute(const MIPSInstruction &cmd) {
        if (typeid(cmd) == typeid(ADDInstruction)) {
            auto typed = dynamic_cast<const ADDInstruction&>(cmd);
            auto dst = typed.rd();
            auto src = typed.rs();
            auto rt = typed.rt();
            int32_t result = (int32_t)m_registers[src] + (int32_t)m_registers[rt];
            m_registers[dst] = (uint32_t)result;
            advanceCP(4U);
        } else if (typeid(cmd) == typeid(JumpInstruction)) {
            auto typed = dynamic_cast<const JumpInstruction&>(cmd);
            uint32_t target = typed.address();
            m_pc = m_npc;
            m_npc = (m_pc & 0xF0000000U) | (target << 2U);
        } else if (typeid(cmd) == typeid(SyscallInstruction)) {
            auto typed = dynamic_cast<const SyscallInstruction&>(cmd);
            auto callId = m_registers[REGISTER_V0];

            switch (callId) {
                case 10U:
                    terminate();
                    break;
                default:
                    std::cout << "No such system call: " << callId << std::endl;
                    break;
            }
            advanceCP(4U);
        } else if (typeid(cmd) == typeid(ORIInstruction)) {
            auto typed = dynamic_cast<const ORIInstruction&>(cmd);
            auto dst = typed.rt();
            auto src = typed.rs();
            auto immediate = typed.immediate();

            uint32_t result = (uint32_t)m_registers[src] | immediate;
            m_registers[dst] = result;
            advanceCP(4U);
        } else if (typeid(cmd) == typeid(BEQInstruction)) {
            auto typed = dynamic_cast<const BEQInstruction&>(cmd);
            auto src = typed.rs();
            auto dst = typed.rt();
            auto offset = typed.immediate();
            auto advance = 4U;

            if (m_registers[src] == m_registers[dst]) {
                advance = offset << 2U;
            }
            advanceCP(advance);
        } else {
            uint32_t ins = cmd.instruction();
            std::cout << "instruction not supported: " << std::hex << "0x" << ins << std::dec << std::endl;
            throw InstructionNotSupportedExeception(ins);
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
        return Util::getWord(m_ram, t_address);
    }

    void CPU::tick() {
        uint32_t ins = getInstruction(m_pc);
        auto instruction = m_parser->parse(ins);
        execute(*instruction);
    }

    uint32_t CPU::npc() const {
        return m_npc;
    }

    CPU::CPU(uint32_t t_pc, RAM &t_ram) :
        m_registers(new uint64_t[32]), m_pc(t_pc), m_npc(t_pc+4U), m_ram(t_ram), m_parser(new InstructionParser()) {}

    CPU::~CPU() {
        delete[] m_registers;
        delete m_parser;
    }

    void CPU::terminate() {
        std::cout << "Program Exit" << std::endl;
        throw ProgramTerminateException();
    }
}
