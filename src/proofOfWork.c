
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include "./proofOfWork.h"

int targetBits = 2;

int startsWith(const char *str, const char *pre)
{
    return strncmp(pre, str, strlen(pre)) == 0;
}

ProofOfWork* NewProofOfWork(Block* b) {
    BYTE* target = malloc(sizeof(BYTE) * (targetBits + 1));
    target[0] = '\0';
    for (int i = 0; i < targetBits; i++) {
        target = strcat(target, "0");
    }

    ProofOfWork* pow = malloc(sizeof(ProofOfWork));
    pow -> block = b;
    pow -> target = target;
    pow -> nonce = 0;
    return pow;
}

BYTE* prepareData(ProofOfWork* pow) {
    BYTE timestampStr[20];
    sprintf(timestampStr, "%lx", pow -> block -> timestamp); 

    BYTE nonceStr[20];
    sprintf(nonceStr, "%lx", pow -> nonce); 

    BYTE targetBitsStr[20];
    sprintf(targetBitsStr, "%x", targetBits); 

    size_t dataSize = strlen(timestampStr) + strlen(pow -> block -> prevBlockHash) + strlen(pow -> block -> data) + strlen(targetBitsStr) + strlen(nonceStr) + (size_t) 1;
    BYTE* data = malloc(sizeof(BYTE) * dataSize);
    data[0] = '\0';

    strcat(data, pow -> block -> prevBlockHash);
    strcat(data, pow -> block -> data);
    strcat(data, timestampStr);
    strcat(data, targetBitsStr);
    strcat(data, nonceStr);
    return data;
}

int validateProofOfWork(ProofOfWork* pow) {
    BYTE* data = prepareData(pow);
    BYTE* hash = sha256(data, strlen(data));

    return strcmp(hash, pow -> block -> hash) == 0; 
}

BYTE* runProofOfWork(ProofOfWork* pow) {
    BYTE* hash;
    BYTE* data;
    printf("Mining the block containting '%s'...\n", pow -> block -> data);
    