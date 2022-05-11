#include <string.h>
#include <stdio.h>

#include "sha256.h"
#include "helpers.h"

void process_first_chunks(char* message, int total);
void process_chunk(h, w);

/**
 * message: Input length
 * length : Length of message (in bits)
 **/
hash sha256(char* message, size_t length) {

    uint32_t h[8];
    for (int i = 0; i < 8; i++)
        h[i] = H[i];

    int num_full_chunks = length / 512;

    process_first_chunks(message, num_full_chunks);

}

void process_first_chunks(char* message, int total) {
    for (int i = 0; i < total; i++) {
        uint32_t w[64];
        memcpy(w, &message[64 * i], 64);
        process_chunk(h, w);
    }
}

