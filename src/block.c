
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

BYTE* generateBlockHash(Block* block) {
    /* 
        generates hash of the block from its data, previous block hash, and timestamp
    */
    if (block == NULL) {
        printf("generateBlockHash | block pointer is NULL\n");
        exit(1);
    }

    BYTE timestampStr[20];
    sprintf(timestampStr, "%u", block -> timestamp); 

    size_t headersSize = strlen(timestampStr) + strlen(block -> prevBlockHash) + strlen(block -> data);
    BYTE* headers = malloc(sizeof(BYTE) * headersSize);
    headers[0] = '\0';

    strcat(headers, block -> prevBlockHash);
    strcat(headers, block -> data);
    strcat(headers, timestampStr);

    BYTE* hash = sha256(headers, strlen(headers));
    free(headers);
    return hash;
}

Block* createBlock(BYTE* data, BYTE* prevBlockHash) {
    /* 
        Creates a block with given data and previous block hash
    */
    Block* block = malloc(sizeof(Block));

    block -> timestamp = (unsigned long) time(NULL);
    block -> data = data;
    block -> prevBlockHash = prevBlockHash;

    // proof of work
    ProofOfWork* pow = NewProofOfWork(block);
    block -> hash = runProofOfWork(pow);
    block -> nonce = pow -> nonce;

    if (strcmp(block -> data, "Steal something") == 0) {
        pow -> nonce++;