//
// Created by ZhihaoJun on 2018-08-22.
//

#ifndef AMC_JUMPINSTRUCTION_H
#define AMC_JUMPINSTRUCTION_H

#include "JInstruction.h"

namespace AMC {
    class JUMPInstruction : public JInstruction {
    public:
        JUMPInstruction(uint32_t t_ins) : JInstruction(t_ins) {}
    };
}

#endif //AMC_JUMPINSTRUCTION_H
