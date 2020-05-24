#!/bin/bash
clear
gcc test.c -I/usr/include/SDL2 -lSDL2 -lSDL2_ttf -o test && ./test
