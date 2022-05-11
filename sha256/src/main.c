#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "sha256.h"
#include "helpers.h"

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 3) {
        printf("Usage: %s [message] [trunc]\n", argv[0]);
        printf("trunc: OPTIONAL number of bits to omit\n");
        return 1;
    }

    int trunc = 0;
    if (argc == 3) {
        trunc = atoi(argv[2]);
    }

    int len = strlen(argv[1]) * 8 - trunc;
    if (len <= 0) {
        printf("Too many bits truncated.\n");
        return 1;
    }

    hash s = sha256(argv[1], len);

    for (int i = 0; i < 32; i++) {
        printf("%x", s.val[i] & 0xff);
    }
    printf("\n");
    return 0;
}
