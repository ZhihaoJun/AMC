cmake_minimum_required(VERSION 3.10)
project(AMC)

add_subdirectory(lib/googletest)
include_directories(include)
include_directories(lib/googletest/include)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")

file(GLOB AMCInstructionsSrc "src/instructions/*.cpp")

add_library(AMC src/CPU.cpp src/InstructionFactory.cpp src/RAM.cpp src/Util.cpp src/ProgramTerminateException.cpp src/InstructionParser.cpp ${AMCInstructionsSrc} src/InstructionNotSupportedExeception.cpp include/InstructionNotSupportedExeception.h)
add_executable(AMCMain main.cpp src/CPU.cpp include/CPU.h src/instructions/MIPSInstruction.cpp include/instructions/MIPSInstruction.h src/instructions/NullInstruction.cpp include/instructions/NullInstruction.h src/instructions/JInstruction.cpp include/instructions/JInstruction.h src/instructions/IInstruction.cpp include/instructions/IInstruction.h src/instructions/RInstruction.cpp include/instructions/RInstruction.h src/instructions/ADDInstruction.cpp include/instructions/ADDInstruction.h src/instructions/ADDIInstruction.cpp include/instructions/ADDIInstruction.h src/instructions/ADDIUInstruction.cpp include/instructions/ADDIUInstruction.h src/RAM.cpp include/RAM.h src/InstructionFactory.cpp include/InstructionFactory.h src/instructions/JumpInstruction.cpp include/instructions/JumpInstruction.h test/test.cpp src/instructions/SyscallInstruction.cpp include/instructions/SyscallInstruction.h src/ProgramTerminateException.cpp include/ProgramTerminateException.h src/Util.cpp include/Util.h src/instructions/ORIInstruction.cpp include/instructions/ORIInstruction.h src/InstructionParser.cpp include/InstructionParser.h src/instructions/BEQInstruction.cpp include/instructions/BEQInstruction.h src/instructions/JRInstruction.cpp include/instructions/JRInstruction.h src/instructions/LUIInstruction.cpp include/instructions/LUIInstruction.h src/InstructionNotSupportedExeception.cpp include/InstructionNotSupportedExeception.h)
add_executable(UnitTest test/test.cpp test/instructions.cpp test/cpu.cpp test/format.cpp)
target_link_libraries(UnitTest gtest_main gtest AMC)
