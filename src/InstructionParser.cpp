//
// Created by January on 8/22/2018.
//

#include "InstructionParser.h"

#include <iostream>
#include <InvalidInstructionException.h>
#include "instructions/all.h"

std::unique_ptr<AMC::MIPSInstruction> AMC::InstructionParser::parse(uint32_t t_ins) {
    auto opcode = (uint8_t)((t_ins >> 26U) & 0x3FU);
    auto funct = (uint8_t)(t_ins & 0x3FU);

    AMC::MIPSInstruction *raw = nullptr;
    if (t_ins == 0U) { // NOOP instruction
        raw = static_cast<AMC::MIPSInstruction *>(new NOOPInstruction());
    } else if (opcode == 0x0U) { // R instruction
        switch (funct) {
            case 0x20U: // ADD instruction
                raw = static_cast<AMC::MIPSInstruction *>(new ADDInstruction(t_ins));
                break;
            case 0x21U: // ADDU instruction
                raw = static_cast<AMC::MIPSInstruction *>(new ADDUInstruction(t_ins));
                break;
            case 0x22U: // SUB instruction
                raw = static_cast<AMC::MIPSInstruction *>(new SUBInstruction(t_ins));
                break;
            case 0x24U: // AND instruction
                raw = static_cast<AMC::MIPSInstruction *>(new ANDInstruction(t_ins));
                break;
            case 0x26U: // XOR instruction
                raw = static_cast<AMC::MIPSInstruction *>(new XORInstruction(t_ins));
                break;
            case 0x1AU: // DIV instruction
                raw = static_cast<AMC::MIPSInstruction *>(new DIVInstruction(t_ins));
                break;
            case 0x18U: // MULT instruction
                raw = static_cast<AMC::MIPSInstruction *>(new MULTInstruction(t_ins));
                break;
            case 0xCU: // Syscall instruction
                raw = static_cast<AMC::MIPSInstruction *>(new SyscallInstruction(t_ins));
                break;
            case 0x10U: // mfhi
                raw = static_cast<AMC::MIPSInstruction *>(new MFHIInstruction(t_ins));
                break;
            case 0x12U: // mflo
                raw = static_cast<AMC::MIPSInstruction *>(new MFLOInstruction(t_ins));
                break;
            default:
                throw InvalidInstructionException(t_ins, InvalidInstructionException::Funct);
        }
    } else if (opcode == 0xDU) { // ORI instruction
        raw = static_cast<AMC::MIPSInstruction *>(new ORIInstruction(t_ins));
    } else if (opcode == 0x20U) { // LB instruction
        raw = static_cast<AMC::MIPSInstruction *>(new LBInstruction(t_ins));
    } else if (opcode == 0x23U) { // LW instruction
        raw = static_cast<AMC::MIPSInstruction *>(new LWInstruction(t_ins));
    } else if (opcode == 0x28U) { // SB instruction
        raw = static_cast<AMC::MIPSInstruction *>(new SBInstruction(t_ins));
    } else if (opcode == 0x2BU) { // SW instruction
        raw = static_cast<AMC::MIPSInstruction *>(new SWInstruction(t_ins));
    } else if (opcode == 0x8U) { // ADDI instruction
        raw = static_cast<AMC::MIPSInstruction *>(new ADDIInstruction(t_ins));
    } else if (opcode == 0x9U) { // ADDIU instruction
        raw = static_cast<AMC::MIPSInstruction *>(new ADDIUInstruction(t_ins));
    } else if (opcode == 0xCU) { // ANDI instruction
        raw = static_cast<AMC::MIPSInstruction *>(new ANDIInstruction(t_ins));
    } else if (opcode == 0xFU) { // LUI instruction
        raw = static_cast<AMC::MIPSInstruction *>(new LUIInstruction(t_ins));
    } else if (opcode == 0x4U) { // BEQ instruction
        raw = static_cast<AMC::MIPSInstruction *>(new BEQInstruction(t_ins));
    } else if (opcode == 0x2U) { // JUMP instruction
        raw = static_cast<AMC::MIPSInstruction *>(new JUMPInstruction(t_ins));
    } else {
        throw InvalidInstructionException(t_ins, InvalidInstructionException::Opcode);
    }
    return std::unique_ptr<AMC::MIPSInstruction>(raw);
}
