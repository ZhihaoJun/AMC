//
// Created by January on 2018/10/20.
//

#include "instructions/ANDIInstruction.h"

uint32_t AMC::ANDIInstruction::instruction() const {
    return IInstruction::instruction();
}

AMC::ANDIInstruction::ANDIInstruction(uint32_t t_ins) : IInstruction(t_ins) {

}

AMC::ANDIInstruction::ANDIInstruction(uint8_t t_rs, uint8_t t_rt, uint16_t t_immediate) :
    IInstruction(0xCU, t_rs, t_rt, t_immediate) {}
