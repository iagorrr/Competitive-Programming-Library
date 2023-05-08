// iagorrr ;)
#include <stdio.h>
#include <stdlib.h>

#define less(a, b) a < b
#define lesseq(a, b) a <= b
#define exchange(a , B) {Item t = a; a = b; b = t;}

typedef int Item;

void merge(Item *v, int l, int r){// [l,r]
    int mid = l + (r-l)/2;
    int pl = l;
    int pr = mid+1;
    int p = 0;
    Item *aux = malloc(sizeof(Item)*(r-l+1));

    while(pl <= mid && pr <= r){
        if(less(v[pl], v[pr]))
            aux[p++] = v[pl++];
        else
            aux[p++] = v[pr++];
    }

    while(pl <= mid)
        aux[p++] = v[pl++];

    while(pr <= r)
        aux[p++] = v[pr++];
    
    p = 0;
    for(int i = l; i <= r; ++i)
        v[i] = aux[p++];

    free(aux);
}
void merge_sort(Item *v, int l , int r){// [l, r]
    if(l >= r) return;

    int mid = l + (r-l)/2;

    merge_sort(v, l, mid);
    merge_sort(v, mid+1 ,r);

    merge(v, l, r);
}
