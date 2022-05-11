#include <stdio.h>

#include "helpers.h"

uint32_t r_rot(uint32_t num, int n) {
    return num << (32 - n) | num >> n;
}

uint32_t r_sft(uint32_t num, int n) {
    return num >> n;
}

int div_ceil(int a, int b) {
    return (a + b - 1) / b;
}

uint32_t bswp32(uint32_t i) {
    return (i << 24) + (i >> 24) +
        ((i & 0x0000ff00) << 8) + 
        ((i & 0x00ff0000) >> 8);
}

uint64_t bswp64(uint64_t i) {
    return bswp32(i >> 32) +
        ((uint64_t) bswp32(i) << 32);
}
