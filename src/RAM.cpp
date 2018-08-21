//
// Created by ZhihaoJun on 2018-08-22.
//

#include "../include/RAM.h"

AMC::RAM::RAM(uint64_t t_size) :
    m_data(new uint8_t[t_size]) {}

AMC::RAM::~RAM() {
    delete[] m_data;
}

uint8_t AMC::RAM::get(uint64_t t_address) const {
    return *(m_data + t_address);
}

void AMC::RAM::set(uint64_t t_address, uint8_t t_value) {
    *(m_data + t_address) = t_value;
}
