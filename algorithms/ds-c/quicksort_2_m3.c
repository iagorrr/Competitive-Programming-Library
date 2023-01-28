/*
 * iagorrr ;)
 * quicksort optimization to avoid worst cases, using '3 pivots'.
 */
#include <stdio.h>

#define less(a, b) a < b 
#define lessexchange(a, b) {if(less(a,b)) exchange(a, b);}
#define greater(a, b) a > b
#define greaterexchange(a,b) {if(greater(a,b)) exchange(a, b);}
#define exchange(a, b) {Item t = a; a = b; b = t;}

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

    int mid = l + (r-l)/2;

    lessexchange(v[mid], v[r]);
    greaterexchange(v[l], v[mid]);
    lessexchange(v[r], v[mid]);

    int i = partition(v, l, r);

    quicksort(v, l, i);
    quicksort(v, i+1, r);
}
