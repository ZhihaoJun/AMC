cmake_minimum_required(VERSION 3.10)
project(AMC)

set(CMAKE_CXX_STANDARD 11)

add_executable(AMC main.cpp src/CPU.cpp include/CPU.h src/instructions/MIPSInstruction.cpp include/instructions/MIPSInstruction.h src/instructions/NullInstruction.cpp include/instructions/NullInstruction.h src/instructions/JInstruction.cpp include/instructions/JInstruction.h src/instructions/IInstruction.cpp include/instructions/IInstruction.h src/instructions/RInstruction.cpp include/instructions/RInstruction.h src/instructions/ADDInstruction.cpp include/instructions/ADDInstruction.h src/instructions/ADDIInstruction.cpp include/instructions/ADDIInstruction.h src/instructions/ADDIUInstruction.cpp include/instructions/ADDIUInstruction.h src/RAM.cpp include/RAM.h src/InstructionFactory.cpp include/InstructionFactory.h src/instructions/JumpInstruction.cpp include/instructions/JumpInstruction.h)