//
// Created by January on 8/22/2018.
//

#include <instructions/ADDInstruction.h>
#include <iostream>
#include <instructions/SyscallInstruction.h>
#include <instructions/ORIInstruction.h>
#include "InstructionParser.h"

std::unique_ptr<AMC::MIPSInstruction> AMC::InstructionParser::parse(uint32_t t_ins) {
    auto opcode = (uint8_t)((t_ins >> 26U) & 0x3FU);
    auto funct = (uint8_t)(t_ins & 0x3FU);

    AMC::MIPSInstruction *raw = nullptr;
    // R instruction
    if (opcode == 0x0U) {
        switch (funct) {
            case 0x20U:
                raw = static_cast<AMC::MIPSInstruction*>(new ADDInstruction(t_ins));
                break;
            case 0xCU:
                raw = static_cast<AMC::MIPSInstruction*>(new SyscallInstruction(t_ins));
                break;
            default:
                std::cout << "[InstructionParser.parse] cannot parse such instruction: " << std::hex << "0x" << t_ins << std::dec << std::endl;
        }
    } else if (opcode == 0xDU) { // ORI instruction
        raw = static_cast<AMC::MIPSInstruction*>(new ORIInstruction(t_ins));
    }
    return std::unique_ptr<AMC::MIPSInstruction>(raw);
}
