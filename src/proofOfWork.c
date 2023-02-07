
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