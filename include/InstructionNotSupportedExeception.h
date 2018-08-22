//
// Created by January on 8/22/2018.
//

#ifndef AMC_INSTRUCTIONNOTSUPPORTEDEXECEPTION_H
#define AMC_INSTRUCTIONNOTSUPPORTEDEXECEPTION_H

#include <exception>
#include <cstdint>

namespace AMC {
    class InstructionNotSupportedExeception : public std::exception {
    public:
        InstructionNotSupportedExeception(uint32_t t_ins);

        uint32_t instruction() const;

    private:
        uint32_t m_ins;
    };
}

#endif //AMC_INSTRUCTIONNOTSUPPORTEDEXECEPTION_H
