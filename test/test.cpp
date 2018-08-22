//
// Created by January on 8/22/2018.
//

#include "gtest/gtest.h"
#include <iostream>

TEST(Hello, AMC) {
    std::cout << "Hello, Another MIPS CPU simulator" << std::endl;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
