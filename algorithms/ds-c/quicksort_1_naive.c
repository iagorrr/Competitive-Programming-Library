// iagorrr ;)
#include <stdio.h>

#define greater(a, b) a > b
#define exchange(a, b) Item t = a; a = b; b = t;
#define less(a, b) a < b 

typedef int Item;

int partition(Item *v, int l, int r){ // [l, r]
    int i = l - 1; 
    int  j = r; 
    Item pivot = v[r];
    for(;;){
        while(less(v[++i], pivot)); 

        while(greater(v[--j], pivot));

        if(i >= j) break; 

        exchange(v[i], v[j]);
    }
	exchange(v[i], v[r]);
    return i; 
}

void quicksort(Item *v,int l, int r) // [l, r]
{
    if(r <= l) return;

    int i = partition(v, l, r);

    quicksort(v, l, i);
    quicksort(v, i+1, r);
}
