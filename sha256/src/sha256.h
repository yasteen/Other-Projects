#ifndef SHA256_H
#define SHA256_H

#include <stdint.h>
#include <stddef.h>

typedef struct {
    char val[32];
} hash;

extern uint32_t H[8];
extern uint32_t k[64];

hash sha256(char* message, size_t length);
void process_chunk(uint32_t h[8], uint32_t w[64]);

#endif

