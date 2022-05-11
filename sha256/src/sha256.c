#include <string.h>
#include <stdio.h>

#include "sha256.h"
#include "helpers.h"

void process_frst_chunks(char* msg, int total, uint32_t h[8]);
void process_last_chunks(char* msg, int total, size_t length, uint32_t h[8]);
void process_chunk(uint32_t h[8], uint32_t w[64]);

/**
 * message: Input length
 * length : Length of message (in bits)
 **/
hash sha256(char* message, size_t length) {

    uint32_t h[8];
    for (int i = 0; i < 8; i++)
        h[i] = H[i];

    int num_full_chunks = length / 512;

    process_frst_chunks(message, num_full_chunks, h);
    process_last_chunks(message, num_full_chunks, length, h);

    hash ans;
    for (int i = 0; i < 8; i++) {
        void* v_ans = ans.val + (i * 4);
        uint32_t* i_ans = v_ans;
        *i_ans = bswp32(h[i]);
    }
    return ans;
}

void process_frst_chunks(char* msg, int total, uint32_t h[8]) {
    for (int i = 0; i < total; i++) {
        uint32_t w[64];
        memcpy(w, &msg[64 * i], 64);
        process_chunk(h, w);
    }
}

void process_last_chunks(char* msg, int total, size_t length, uint32_t h[8]) {
    uint32_t w[64] = {};
    uint32_t x[64] = {};

    int bits_left = length % 512;
    int bytes_left = bits_left / 8;

    memcpy(w, &msg[total], div_ceil(bits_left, 8));
    void * v_w = w; char* c_w = v_w;

    int clear_bits = 8 - (bits_left - bytes_left * 8);

    c_w[bytes_left] &= 0xff - ((0x1 << clear_bits) - 1);
    c_w[bytes_left] |= 0x1 << (clear_bits - 1);

    uint32_t* last_blk = w;
    if (bits_left > 256 - 65) {
        process_chunk(h, w);
        last_blk = x;
    }
    void* v_lb = last_blk; uint64_t* i_lb = v_lb;

    uint64_t len = bswp64(length);
    i_lb[7] = len;
    process_chunk(h, last_blk);
}

void process_chunk(uint32_t h[8], uint32_t w[64]) {
    for (int i = 16; i < 64; i++) {
        uint32_t w15 = bswp32(w[i - 15]);
        uint32_t s0 = r_rot(w15, 7) ^ r_rot(w15, 18) ^ r_sft(w15, 3);
        uint32_t w2 = bswp32(w[i - 2]);
        uint32_t s1 = r_rot(w2, 17) ^ r_rot(w2, 19) ^ r_sft(w2, 10);
        uint32_t w16 = bswp32(w[i - 16]);
        uint32_t w7 = bswp32(w[i - 7]);
        w[i] = bswp32(w16 + s0 + w7 + s1);
    }
    uint32_t a[8];
    for (int i = 0; i < 8; i++)
        a[i] = h[i];
    
    for (int i = 0; i < 64; i++) {
        uint32_t s0 = r_rot(a[0], 2) ^ r_rot(a[0], 13) ^ r_rot(a[0], 22);
        uint32_t s1 = r_rot(a[4], 6) ^ r_rot(a[4], 11) ^ r_rot(a[4], 25);
        uint32_t ch = (a[4] & a[5]) ^ (~a[4] & a[6]);
        uint32_t wi = bswp32(w[i]);
        uint32_t t1 = a[7] + s1 + ch + k[i] + wi;
        uint32_t mj = (a[0]&a[1]) ^ (a[0]&a[2]) ^ (a[1]&a[2]);
        uint32_t t2 = s0 + mj;

        a[7] = a[6]; a[6] = a[5]; a[5] = a[4]; a[4] = a[3] + t1;
        a[3] = a[2]; a[2] = a[1]; a[1] = a[0]; a[0] = t1 + t2;
    }

    for (int i = 0; i < 8; i++) {
        h[i] += a[i];
    }
}

