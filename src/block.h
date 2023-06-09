
#include <stddef.h>

typedef unsigned char BYTE;    
typedef struct{
    unsigned long int timestamp;
    unsigned long int nonce;
    BYTE* data;
    BYTE* prevBlockHash;
    BYTE* hash;
} Block;

Block* createBlock(BYTE* data, BYTE* prevBlockHash);
Block* newGenesisBlock();
BYTE* sha256(BYTE* data, size_t len);