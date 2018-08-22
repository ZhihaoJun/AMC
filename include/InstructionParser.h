//
// Created by January on 8/22/2018.
//

#ifndef AMC_INSTRUCTIONPARSER_H
#define AMC_INSTRUCTIONPARSER_H

#include <memory>
#include <cstdint>
#include <instructions/MIPSInstruction.h>

namespace AMC {
    class InstructionParser {
    public:
        std::unique_ptr<MIPSInstruction> parse(uint32_t t_ins);
    };
}

#endif //AMC_INSTRUCTIONPARSER_H
