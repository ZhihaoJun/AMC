//
// Created by January on 8/21/2018.
//

#include <iostream>
#include <instructions/ORIInstruction.h>
#include <instructions/BEQInstruction.h>
#include <instructions/LBInstruction.h>
#include <instructions/SBInstruction.h>
#include <instructions/LWInstruction.h>
#include <instructions/SWInstruction.h>
#include <instructions/ADDIUInstruction.h>
#include <instructions/LUIInstruction.h>
#include <instructions/ADDIInstruction.h>
#include <instructions/MFHIInstruction.h>
#include <instructions/MFLOInstruction.h>

#include "ProgramTerminateException.h"
#include "InstructionNotSupportedExeception.h"
#include "../include/CPU.h"
#include "../include/instructions/ADDInstruction.h"
#include "instructions/JUMPInstruction.h"
#include "instructions/SyscallInstruction.h"
#include "Util.h"
#include "instructions/SUBInstruction.h"

namespace AMC {
    uint64_t CPU::readRegister(int id) const {
        return *(m_registers+id);
    }

    void CPU::execute(const MIPSInstruction &cmd) {
        if (typeid(cmd) == typeid(ADDInstruction)) {
            auto typed = dynamic_cast<const ADDInstruction &>(cmd);
            auto dst = typed.rd();
            auto src = typed.rs();
            auto rt = typed.rt();

            int32_t result = (int32_t) reg(src) + (int32_t) reg(dst);
            reg(dst) = (uint32_t) result;
            advanceCP(ALIGN_BYTES);
        } else if (typeid(cmd) == typeid(ADDIInstruction)) {
            auto typed = dynamic_cast<const ADDIInstruction &>(cmd);
            auto dst = typed.rt();
            auto src = typed.rs();
            auto immediate = typed.immediate();

            int32_t result = (int32_t) reg(src) + (int16_t) immediate;
            reg(dst) = (uint32_t)result;
            advanceCP(ALIGN_BYTES);
        } else if (typeid(cmd) == typeid(ADDIUInstruction)) {
            auto typed = dynamic_cast<const ADDIUInstruction &>(cmd);
            auto dst = typed.rt();
            auto src = typed.rs();
            auto immediate = typed.immediate();

            uint32_t result = (uint32_t) reg(src) + immediate;
            reg(dst) = result;
            advanceCP(ALIGN_BYTES);
        } else if (typeid(cmd) == typeid(SUBInstruction)) {
            auto typed = dynamic_cast<const SUBInstruction &>(cmd);
            auto dst = typed.rd();
            auto src = typed.rs();
            auto rt = typed.rt();

            int32_t result = (int32_t) reg(src) - (int32_t) reg(rt);
            reg(dst) = (uint32_t)result;
            advanceCP(ALIGN_BYTES);
        } else if (typeid(cmd) == typeid(JUMPInstruction)) {
            auto typed = dynamic_cast<const JUMPInstruction&>(cmd);
            uint32_t target = typed.address();
            m_pc = (m_pc & 0xF0000000U) | (target << 2U);
            m_npc = m_pc + ALIGN_BYTES;
        } else if (typeid(cmd) == typeid(SyscallInstruction)) {
            auto typed = dynamic_cast<const SyscallInstruction &>(cmd);
            auto callId = reg(REGISTER_V0);

            uint64_t a0 = 0U;
            uint64_t offset = 0U;
            uint8_t c = 0U;
            switch (callId) {
                case 10U:
                    terminate();
                    break;
                case 4U: // print string
                    a0 = reg(REGISTER_A0);
                    offset = 0U;
                    c = m_ram.get(a0);
                    while (c != 0U) {
                        std::cout << (char)c;
                        ++offset;
                        c = m_ram.get(a0 + offset);
                    }
                    break;
                default:
                    std::cout << "No such system call: " << callId << std::endl;
                    break;
            }
            advanceCP(ALIGN_BYTES);
        } else if (typeid(cmd) == typeid(ORIInstruction)) {
            auto typed = dynamic_cast<const ORIInstruction &>(cmd);
            auto dst = typed.rt();
            auto src = typed.rs();
            auto immediate = typed.immediate();

            uint32_t result = (uint32_t)reg(src) | immediate;
            reg(dst) = result;
            advanceCP(ALIGN_BYTES);
        } else if (typeid(cmd) == typeid(BEQInstruction)) {
            auto typed = dynamic_cast<const BEQInstruction &>(cmd);
            auto src = typed.rs();
            auto dst = typed.rt();
            auto offset = typed.immediate();
            auto advance = ALIGN_BYTES;

            if (reg(src) == reg(dst)) {
                advance = offset << 2U;
            }
            advanceCP(advance);
        } else if (typeid(cmd) == typeid(MFHIInstruction)) {
            auto typed = dynamic_cast<const MFHIInstruction &>(cmd);
            auto dst = typed.rd();

            reg(dst) = m_hi;
            advanceCP(ALIGN_BYTES);
        } else if (typeid(cmd) == typeid(MFLOInstruction)) {
            auto typed = dynamic_cast<const MFLOInstruction &>(cmd);
            auto dst = typed.rd();

            reg(dst) = m_lo;
            advanceCP(ALIGN_BYTES);
        } else if (typeid(cmd) == typeid(LUIInstruction)) {
            auto typed = dynamic_cast<const LUIInstruction &>(cmd);
            auto dst = typed.rt();
            auto immediate = typed.immediate();

            reg(dst) = immediate << 16U;
            advanceCP(ALIGN_BYTES);
        } else if (typeid(cmd) == typeid(LBInstruction)) {
            auto typed = dynamic_cast<const LBInstruction &>(cmd);
            auto src = typed.rs();
            auto dst = typed.rt();
            auto offset = typed.immediate();

            auto address = reg(src) + offset;
            reg(dst) = m_ram.get(address);
            advanceCP(ALIGN_BYTES);
        } else if (typeid(cmd) == typeid(SBInstruction)) {
            auto typed = dynamic_cast<const SBInstruction &>(cmd);
            auto src = typed.rs();
            auto dst = typed.rt();
            auto offset = typed.immediate();

            auto address = reg(src) + offset;
            m_ram.set(address, (uint8_t) (reg(dst) & 0xFFU));
            advanceCP(ALIGN_BYTES);
        } else if (typeid(cmd) == typeid(LWInstruction)) {
            auto typed = dynamic_cast<const LWInstruction &>(cmd);
            auto src = typed.rs();
            auto dst = typed.rt();
            auto offset = typed.immediate();

            auto address = reg(src) + offset;
            reg(dst) = Util::loadWord(m_ram, address);
            advanceCP(ALIGN_BYTES);
        } else if (typeid(cmd) == typeid(SWInstruction)) {
            auto typed = dynamic_cast<const SWInstruction &>(cmd);
            auto src = typed.rs();
            auto dst = typed.rt();
            auto offset = typed.immediate();

            auto address = reg(src) + offset;
            Util::storeWord(m_ram, address, (uint32_t) reg(dst));
            advanceCP(ALIGN_BYTES);
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
        return Util::loadWord(m_ram, t_address);
    }

    void CPU::tick() {
        uint32_t ins = getInstruction(m_pc);
        auto instruction = m_parser->parse(ins);
        execute(*instruction);
    }

    uint32_t CPU::npc() const {
        return m_npc;
    }

    CPU::CPU(uint32_t t_pc, uint64_t t_sp, uint64_t t_gp, RAM &t_ram) :
        m_registers(new uint64_t[32]), m_pc(t_pc), m_npc(t_pc+4U), m_hi(0x0U),
        m_lo(0x0U), m_ram(t_ram), m_parser(new InstructionParser()) {

        for (int i=0; i<32; ++i) {
            m_registers[i] = 0U;
        }
        reg(REGISTER_SP) = t_sp;
        reg(REGISTER_GP) = t_gp;
    }

    CPU::~CPU() {
        delete[] m_registers;
        delete m_parser;
    }

    void CPU::terminate() {
        std::cout << "Program Exit" << std::endl;
        throw ProgramTerminateException();
    }

    uint64_t &CPU::reg(uint8_t id) {
        return *(m_registers + id);
    }

    uint32_t CPU::hi() const {
        return m_hi;
    }

    uint32_t CPU::lo() const {
        return m_lo;
    }
}
