//
// Created by January on 8/23/2018.
//

#include <RAM.h>
#include <Util.h>
#include "gtest/gtest.h"
#include <path.hpp>
#include <CPU.h>
#include <ProgramTerminateException.h>
#include <InstructionNotSupportedExeception.h>

TEST(Util, loadFile) {
    auto parentPath = apathy::Path(__FILE__).parent();
    auto abspath = apathy::Path::join(parentPath, "./files/test").sanitize();

    AMC::RAM ram(1024*1024); // 1MB
    AMC::Util::loadFile(ram, 0x0U, abspath.string());
}
