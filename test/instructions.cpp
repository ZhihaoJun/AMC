//
// Created by January on 8/22/2018.
//

#include <gtest/gtest.h>
#include <instructions/RInstruction.h>
#include <instructions/JInstruction.h>
#include "instructions/IInstruction.h"

TEST(Instructions, IInstruction) {
    auto code = 0x8E843782U;
    AMC::IInstruction ins(code);

    EXPECT_EQ(ins.opcode(), 0x23U);
    EXPECT_EQ(ins.rs(), 0x14U);
    EXPECT_EQ(ins.rt(), 0x4U);
    EXPECT_EQ(ins.immediate(), 0x3782U);
    EXPECT_EQ(ins.instruction(), code);
}

TEST(Instructions, RInstruction) {
    auto code = 0x48378193U;
    AMC::RInstruction ins(code);

    EXPECT_EQ(ins.opcode(), 0x12U);
    EXPECT_EQ(ins.rs(), 0x1U);
    EXPECT_EQ(ins.rt(), 0x17U);
    EXPECT_EQ(ins.rd(), 0x10U);
    EXPECT_EQ(ins.shamt(), 0x6U);
    EXPECT_EQ(ins.funct(), 0x13U);
    EXPECT_EQ(ins.instruction(), code);
}

TEST(Instructions, JInstruction) {
    auto code = 0x32789123U;
    AMC::JInstruction ins(code);

    EXPECT_EQ(ins.opcode(), 0xCU);
    EXPECT_EQ(ins.address(), 0x2789123U);
}
