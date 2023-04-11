// iagorrr ;)
#include <stdio.h>

typedef int Item;
#define less(a, b) a < b 
#define greater(a, b) a > b
#define exchange(a, b) Item t = a; a = b; b = t;

int partition(Item *v, int l, int r){
    int i = l - 1; 
    int  j = r; 
    Item pivot = v[r];
    for(;;){
        while(less(v[++i], pivot)); 

        while(less(pivot, v[--j])) if(j==l) break;

        if(i >= j) break; 

        exchange(v[i], v[j]);
    }
	exchange(v[i], v[r]);
    return i; 
}

