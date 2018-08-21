//
// Created by ZhihaoJun on 2018-08-22.
//

#ifndef AMC_RAM_H
#define AMC_RAM_H

#include <cstdint>

namespace AMC {
    class RAM {
    public:
        RAM(uint64_t t_size);
        ~RAM();

        uint8_t get(uint64_t t_address) const;
        void set(uint64_t t_address, uint8_t t_value);

    private:
        uint8_t *m_data;
    };
}

#endif //AMC_RAM_H
