
#include "./src/blockchain.h"
#include <stdio.h>

int main() {
    Blockchain* bc = createBlockChain();
    
    AddBlock(bc, "Send 1 BTC to Stepan");
    AddBlock(bc, "Steal something");
    AddBlock(bc, "Send 2 more BTC to Stepan");

    for (int i = 0; i < bc -> length; i++) {
        printf("Timestamp: %d\n", bc -> blocks[i] -> timestamp);
        printf("Prev. hash: ");
        for (int j = 0; j < 32; j++) {
            printf("%d,", bc -> blocks[i] -> prevBlockHash[j]);
        }
        printf("\n");
        printf("Data: %s\n", bc -> blocks[i] -> data);