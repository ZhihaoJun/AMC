//
// Created by ZhihaoJun on 2018-08-22.
//

#ifndef AMC_ADDIUINSTRUCTION_H
#define AMC_ADDIUINSTRUCTION_H

#include "IInstruction.h"

namespace AMC {
    class ADDIUInstruction : public IInstruction {
    public:
        ADDIUInstruction(uint32_t t_ins) : IInstruction(t_ins) {}
        ADDIUInstruction(uint8_t t_rs, uint8_t t_rt, uint16_t t_immediate) :
                IInstruction(0x9U, t_rs, t_rt, t_immediate) {}
        ~ADDIUInstruction() override = default;
    };
}

#endif //AMC_ADDIUINSTRUCTION_H
