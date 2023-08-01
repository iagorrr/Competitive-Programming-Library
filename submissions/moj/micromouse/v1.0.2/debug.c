#ifndef DEBUGATOR
#define DEBUGATOR

#include <stdio.h>

#include "map.c"

void printBits(int a, int n) {
        for (int i = n - 1; i >= 0; i--) {
                // fprintf(stderr, "%d", (a >> i)&1);
        }
}

void logger(char *msg, int n) {
        // fprintf(stderr, "LOG: {%d, %d} d: [%d] depht: [%d] [%s]\n",
        // current_cord.i, current_cord.j, direction, n, msg);
}

#endif
