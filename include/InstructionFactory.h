//
// Created by ZhihaoJun on 2018-08-22.
//

#ifndef AMC_INSTRUCTIONFACTORY_H
#define AMC_INSTRUCTIONFACTORY_H

#include <memory>
#include "instructions/MIPSInstruction.h"

namespace AMC {
    class InstructionFactory {
    public:
        std::shared_ptr<MIPSInstruction> instance(uint32_t t_ins) const;
    };
}

#endif //AMC_INSTRUCTIONFACTORY_H
