
#include "./block.h"

typedef struct {
    Block* block;
    BYTE* target;
    long unsigned int nonce;
} ProofOfWork;

ProofOfWork* NewProofOfWork(Block* b);
BYTE* runProofOfWork(ProofOfWork* pow);
int validateProofOfWork(ProofOfWork* pow);