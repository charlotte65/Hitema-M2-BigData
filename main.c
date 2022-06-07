
#include "./src/blockchain.h"
#include <stdio.h>

int main() {
    Blockchain* bc = createBlockChain();
    
    AddBlock(bc, "Send 1 BTC to Stepan");
    AddBlock(bc, "Steal something");
    AddBlock(bc, "Send 2 more BTC to Stepan");