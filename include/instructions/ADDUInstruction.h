//
// Created by January on 2018/10/20.
//

#ifndef AMC_ADDUINSTRUCTION_H
#define AMC_ADDUINSTRUCTION_H

#include <instructions/RInstruction.h>

namespace AMC {
    class ADDUInstruction : public RInstruction {
    public:
        ADDUInstruction(uint32_t t_ins) : RInstruction(t_ins) {}
        ADDUInstruction(uint8_t t_rs, uint8_t t_rt, uint8_t t_rd) :
                RInstruction(0x0U, t_rs, t_rt, t_rd, 0x0U, 0x24U) {}
        ~ADDUInstruction() override = default;
    };
}

#endif //AMC_ADDUINSTRUCTION_H
