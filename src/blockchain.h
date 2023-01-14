
#include "./block.h"
#include <stddef.h>

typedef struct {
    unsigned int length;
    Block** blocks;
} Blockchain;

void AddBlock(Blockchain* bc, BYTE* data);
Blockchain* createBlockChain();