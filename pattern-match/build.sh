#!/bin/bash
OPTIMIZE_FLAGS="-O3 -march=native -mtune=native -pipe"
gcc ${OPTIMIZE_FLAGS} match.c -o match && ./match
