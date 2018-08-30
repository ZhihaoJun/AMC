//
// Created by January on 8/22/2018.
//

#include <gtest/gtest.h>
#include <path.hpp>
#include <CPU.h>
#include <instructions/ADDInstruction.h>
#include <instructions/SyscallInstruction.h>
#include <instructions/ORIInstruction.h>
#include <ProgramTerminateException.h>
#include <InstructionNotSupportedExeception.h>
#include <InvalidInstructionException.h>
#include <chrono>
#include <Timer.h>
#include "Util.h"

static auto parentPath = apathy::Path(__FILE__).parent();

TEST(CPU, execute) {
    AMC::RAM ram(1024*1024); // 1MB
    AMC::CPU cpu(0x0U, 0x1200U, 0x800U, ram);

    AMC::Util::storeWord(ram, 0x0U, AMC::ADDInstruction(0x8U, 0x9U, 0xAU).instruction());
    AMC::Util::storeWord(ram, 0x4U, AMC::ORIInstruction(AMC::CPU::REGISTER_ZERO, AMC::CPU::REGISTER_V0, 10U).instruction());
    AMC::Util::storeWord(ram, 0x8U, AMC::SyscallInstruction().instruction());

    while (true) {
        try {
            cpu.tick();
        } catch (const AMC::ProgramTerminateException &) {
            break;
        }
    }
}

TEST(CPU, printString) {
    AMC::RAM ram(1024*1024); // 1MB
    AMC::CPU cpu(0x0U, 0x1200U, 0x800U, ram);

    AMC::Util::storeString(ram, 0x800U, "Hello, World!\n");
    AMC::Util::storeWord(ram, 0x0U, AMC::ORIInstruction(AMC::CPU::REGISTER_ZERO, AMC::CPU::REGISTER_V0, 4U).instruction());
    AMC::Util::storeWord(ram, 0x4U, AMC::ORIInstruction(AMC::CPU::REGISTER_ZERO, AMC::CPU::REGISTER_A0, 0x800U).instruction());
    AMC::Util::storeWord(ram, 0x8U, AMC::SyscallInstruction().instruction());
    AMC::Util::storeWord(ram, 0xCU, AMC::ORIInstruction(AMC::CPU::REGISTER_ZERO, AMC::CPU::REGISTER_V0, 10U).instruction());
    AMC::Util::storeWord(ram, 0x10U, AMC::SyscallInstruction().instruction());

    while (true) {
        try {
            cpu.tick();
        } catch (const AMC::ProgramTerminateException &) {
            break;
        } catch (const AMC::InstructionNotSupportedExeception &) {
            // do nothing
        }
    }
}

TEST(CPU, loadHelloAndExecute) {
    auto code = apathy::Path::join(parentPath, "./files/hello").sanitize();
    auto data = apathy::Path::join(parentPath, "./files/hello_data").sanitize();

    AMC::RAM ram(1024*1024);
    AMC::Util::loadFile(ram, 0x0U, code.string());
    AMC::Util::loadFile(ram, 0x2000U, data.string());
    AMC::CPU cpu(0x0U, 0x2400U, 0x2000U, ram);

    while (true) {
        try {
            cpu.tick();
        } catch (const AMC::ProgramTerminateException &) {
            break;
        } catch (const AMC::InstructionNotSupportedExeception &) {
            // do nothing
        }
    }
}

TEST(CPU, loadSimpleLoopAndExecute) {
    auto code = apathy::Path::join(parentPath, "./files/simple_loop").sanitize();

    AMC::RAM ram(1024*1024);
    AMC::Util::loadFile(ram, 0x0U, code.string());
    AMC::CPU cpu(0x0U, 0x2400U, 0x2000U, ram);

    AMC::Timer timer;
    while (true) {
        try {
            cpu.tick();
        } catch (const AMC::ProgramTerminateException &e) {
            break;
        } catch (const AMC::InstructionNotSupportedExeception &) {
            // do nothing
        } catch (const AMC::InvalidInstructionException &e) {
            throw e;
        }
    }
    std::cout << "elapsed " << timer.elapsedMilli() << " ms" << std::endl;
}
