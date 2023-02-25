
#include "./block.h"

typedef struct {
    Block* block;
    BYTE* target;
    long unsigned int nonce;
} ProofOfWork;
