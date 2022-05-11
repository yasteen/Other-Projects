#ifndef HELPERS_H
#define HELPERS_H

#include <stdint.h>

uint32_t r_rot(uint32_t num, int n);
uint32_t r_sft(uint32_t num, int n);
int div_ceil(int a, int b);

uint32_t bswp32(uint32_t i);
uint64_t bswp64(uint64_t i);

#endif
