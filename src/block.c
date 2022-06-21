
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../lib/sha256.h"
#include "./proofOfWork.h"

BYTE* sha256(BYTE* data, size_t len) {
    /* 
        Creates 32-byte hash from data with size len using SHA256 algorithm
        wrapper around lib/sha256.c
    */
    SHA256_CTX myCtx;
    sha256_init(&myCtx);
    sha256_update(&myCtx, data, len);

    BYTE* hash = malloc(sizeof(BYTE) * 32);
    sha256_final(&myCtx, hash);
    return hash;
} 
