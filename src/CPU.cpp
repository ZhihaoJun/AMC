//
// Created by January on 8/21/2018.
//

#include "../include/CPU.h"

uint64_t AMC::CPU::readRegister(int id) const {
    return m_registers[id];
}

void AMC::CPU::execute(const AMC::MIPSInstruction &cmd) {

}
