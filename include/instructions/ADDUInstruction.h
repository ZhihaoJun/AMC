//
// Created by January on 2018/10/20.
//

#ifndef AMC_ADDUINSTRUCTION_H
#define AMC_ADDUINSTRUCTION_H

#include <instructions/RInstruction.h>

namespace AMC {
    class ADDUInstruction : public RInstruction {
    public:
        ADDUInstruction(uint32_t t_ins);
        ADDUInstruction(uint8_t t_rs, uint8_t t_rt, uint8_t t_rd);
        ~ADDUInstruction() override;

        uint32_t instruction() const override;
    };
}

#endif //AMC_ADDUINSTRUCTION_H
