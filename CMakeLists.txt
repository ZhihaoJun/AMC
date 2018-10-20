cmake_minimum_required(VERSION 3.10)
project(AMC)

add_subdirectory(lib/googletest)
include_directories(include lib/googletest/include lib/apathy)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")

file(GLOB AMCInstructionsSrc "src/instructions/*.cpp")
file(GLOB AMCInstructionsInclude "src/instructions/*.h")
file(GLOB AMCSrc "src/*.cpp")
file(GLOB AMCInclude "include/*.h")

add_library(AMC ${AMCSrc} ${AMCInstructionsSrc} src/instructions/ADDUInstruction.cpp include/instructions/ADDUInstruction.h src/instructions/ANDInstruction.cpp include/instructions/ANDInstruction.h src/instructions/ANDIInstruction.cpp include/instructions/ANDIInstruction.h)
add_executable(AMCMain main.cpp ${AMCSrc} ${AMCInclude} ${AMCInstructionsSrc} ${AMCInstructionsInclude})
add_executable(UnitTest test/test.cpp test/instructions.cpp test/cpu.cpp test/format.cpp test/util.cpp)
target_link_libraries(UnitTest gtest_main gtest AMC)
