#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "blockchain.h"

void AddBlock(Blockchain* bc, BYTE* data) {
    Block* prevBlock = bc -> blocks[bc -> length - 1];
    Block* newBlock = c