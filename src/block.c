
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../lib/sha256.h"
#include "./proofOfWork.h"

BYTE* sha256(BYTE* data, size_t len) {
    /* 