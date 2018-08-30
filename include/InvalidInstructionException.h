//
// Created by January on 8/30/2018.
//

#ifndef AMC_INVALIDINSTRUCTIONEXCEPTION_H
#define AMC_INVALIDINSTRUCTIONEXCEPTION_H

#include <exception>
#include <cstdint>

namespace AMC {
    class InvalidInstructionException : public std::exception {
    public:
        enum InvalidType {
            Opcode,
            Funct
        };

        InvalidInstructionException(uint32_t t_ins, InvalidType t_invalidType);

        uint32_t instruction() const;
        InvalidType invalidType() const;
    private:
        uint32_t m_ins;
        InvalidType m_invalidType;
    };
}

#endif //AMC_INVALIDINSTRUCTIONEXCEPTION_H
