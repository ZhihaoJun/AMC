//
// Created by January on 8/22/2018.
//

#include "Util.h"

uint32_t AMC::Util::getWord(AMC::RAM &t_ram, uint64_t t_address) {
    auto i1 = t_ram.get(t_address);
    auto i2 = t_ram.get(t_address+1U);
    auto i3 = t_ram.get(t_address+2U);
    auto i4 = t_ram.get(t_address+3U);
    return (uint32_t)(i4 << 24U | i3 << 16U | i2 << 8U | i1);
}

void AMC::Util::setWord(AMC::RAM &t_ram, uint64_t t_address, uint32_t t_word) {
    auto i1 = (uint8_t)(t_word & 0xFFU);
    auto i2 = (uint8_t)((t_word >> 8U) & 0xFFU);
    auto i3 = (uint8_t)((t_word >> 16U) & 0xFFU);
    auto i4 = (uint8_t)((t_word >> 24U) & 0xFFU);
    t_ram.set(t_address, i1);
    t_ram.set(t_address+1U, i2);
    t_ram.set(t_address+2U, i3);
    t_ram.set(t_address+3U, i4);
}
