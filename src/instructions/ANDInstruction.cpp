//
// Created by January on 2018/10/20.
//

#include "instructions/ANDInstruction.h"

AMC::ANDInstruction::ANDInstruction(uint32_t t_ins) : RInstruction(t_ins) {

}

AMC::ANDInstruction::ANDInstruction(uint8_t t_rs, uint8_t t_rt, uint8_t t_rd) :
    RInstruction(0x0U, t_rs, t_rt, t_rd, 0x0U, 0x21U) {}

AMC::ANDInstruction::~ANDInstruction() = default;

uint32_t AMC::ANDInstruction::instruction() const {
    return RInstruction::instruction();
}
