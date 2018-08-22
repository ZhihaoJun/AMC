//
// Created by January on 8/22/2018.
//

#ifndef AMC_JRINSTRUCTION_H
#define AMC_JRINSTRUCTION_H

#include <instructions/RInstruction.h>

namespace AMC {
    class JRInstruction : public RInstruction {
    public:
        JRInstruction(uint8_t t_rs);
        JRInstruction(uint32_t t_ins);
    };
}

#endif //AMC_JRINSTRUCTION_H
