//
// Created by ZhihaoJun on 2018-08-22.
//

#include "../include/InstructionFactory.h"

std::shared_ptr<AMC::MIPSInstruction> AMC::InstructionFactory::instance(uint32_t t_ins) const {
    return std::shared_ptr<AMC::MIPSInstruction>();
}
