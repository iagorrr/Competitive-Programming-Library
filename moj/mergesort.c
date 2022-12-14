// iagorrr ;)
#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define LESS(a, b) a < b
#define LESSEQ(a, b) a <= b
#define SWAP(a , B) {Item t = a; a = b; b = t;}

void merge(Item *v, int l, int r){// [l,r]
    int mid = l + (r-l)/2;
    int pl = l;
    int pr = mid+1;
    int p = 0;
    Item aux[r-l+1];

    while(pl <= mid && pr <= r){
        if(LESS(v[pl], v[pr]))
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
}
void merge_sort(Item *v, int l , int r){// [l, r]
    // unitary vector.
    if(l >= r) return;

    int mid = l + (r-l)/2;
    // sort first and second half.
    merge_sort(v, l, mid);
    merge_sort(v, mid+1 ,r);

    // with both sorted just merge it.
    merge(v, l, r);
}

int main(){
    int n = 0;
    Item v[100000+66];
    while(scanf("%d", &v[n++]) != EOF){}
    
    
    --n;

    merge_sort(&v[0], 0, n-1);

    printf("%d", v[0]);
    for(int i = 1; i < n; ++i)
        printf(" %d", v[i]);
    printf("\n");
    return 0;
}

// AC.