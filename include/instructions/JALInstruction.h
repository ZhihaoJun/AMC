//
// Created by January on 8/23/2018.
//

#ifndef AMC_JALINSTRUCTION_H
#define AMC_JALINSTRUCTION_H

#include <instructions/JInstruction.h>

namespace AMC {
    class JALInstruction : public JInstruction {
    public:
        JALInstruction(uint32_t t_ins);

        uint32_t instruction() const override;
    };
}

#endif //AMC_JALINSTRUCTION_H
