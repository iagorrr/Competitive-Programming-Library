// iagorrr ;)
#include <stdio.h>

typedef int Item;
#define LESS(a, b) a < b 
#define EXCH(a, b) Item t = a; a = b; b = t;

int partition(Item *v, int l, int r){
    int i = l - 1; // -1 because uses prefixed increment.
    int  j = r; // pivot element

    for(;;){
        while(LESS(v[++i], v[r])); // finds first position greater than pivot.
        while(LESS(v[r], v[--j])) if(j == l) break; // first position from right to left lower than pivot.

        if(i >= j) break; // the partition is kinda complete.
        EXCH(v[i], v[j]);
    }
	EXCH(v[i], v[r]);
    return i; // position of pivot.
}




