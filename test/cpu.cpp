//
// Created by January on 8/22/2018.
//

#include <gtest/gtest.h>
#include <CPU.h>
#include <instructions/ADDInstruction.h>
#include <instructions/SyscallInstruction.h>
#include <instructions/ORIInstruction.h>
#include <ProgramTerminateException.h>
#include "Util.h"

TEST(CPU, execute) {
    AMC::RAM ram(1024*1024); // 1MB
    AMC::CPU cpu(0x0U, ram);

    AMC::Util::setWord(ram, 0x0U, AMC::ADDInstruction(0x8U, 0x9U, 0xAU).instruction());
    AMC::Util::setWord(ram, 0x4U, AMC::ORIInstruction(AMC::CPU::REGISTER_ZERO, AMC::CPU::REGISTER_V0, 10U).instruction());
    AMC::Util::setWord(ram, 0x8U, AMC::SyscallInstruction().instruction());

    while (true) {
        try {
            cpu.tick();
        } catch (const AMC::ProgramTerminateException &) {
            break;
        }
    }
}
