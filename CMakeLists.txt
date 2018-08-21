cmake_minimum_required(VERSION 3.10)
project(AMC)

set(CMAKE_CXX_STANDARD 11)

add_executable(AMC main.cpp src/CPU.cpp include/CPU.h src/commands/MIPSInstruction.cpp include/commands/MIPSInstruction.h src/commands/NullInstruction.cpp include/commands/NullInstruction.h src/commands/JInstruction.cpp include/commands/JInstruction.h src/commands/IInstruction.cpp include/commands/IInstruction.h src/commands/RInstruction.cpp include/commands/RInstruction.h src/commands/ADDInstruction.cpp include/commands/ADDInstruction.h src/commands/ADDIInstruction.cpp include/commands/ADDIInstruction.h)