//
// Created by January on 8/22/2018.
//

#include <instructions/ADDInstruction.h>
#include <iostream>
#include <instructions/SyscallInstruction.h>
#include <instructions/ORIInstruction.h>
#include <instructions/LBInstruction.h>
#include <instructions/LWInstruction.h>
#include <instructions/SBInstruction.h>
#include <instructions/SWInstruction.h>
#include <instructions/ADDIUInstruction.h>
#include <instructions/LUIInstruction.h>
#include <instructions/ADDIInstruction.h>
#include <instructions/MFHIInstruction.h>
#include <instructions/MFLOInstruction.h>
#include <instructions/BEQInstruction.h>
#include <instructions/JUMPInstruction.h>
#include <InvalidInstructionException.h>
#include "InstructionParser.h"
#include "instructions/SUBInstruction.h"

std::unique_ptr<AMC::MIPSInstruction> AMC::InstructionParser::parse(uint32_t t_ins) {
    auto opcode = (uint8_t)((t_ins >> 26U) & 0x3FU);
    auto funct = (uint8_t)(t_ins & 0x3FU);

    AMC::MIPSInstruction *raw = nullptr;
    // R instruction
    if (opcode == 0x0U) {
        switch (funct) {
            case 0x20U: // ADD instruction
                raw = static_cast<AMC::MIPSInstruction *>(new ADDInstruction(t_ins));
                break;
            case 0x22U: // SUB instruction
                raw = static_cast<AMC::MIPSInstruction *>(new SUBInstruction(t_ins));
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
