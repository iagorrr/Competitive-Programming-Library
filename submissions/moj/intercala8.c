// iagorrr ;)
#include <stdio.h>
#include <stdlib.h>

typedef long long Item;

#define LESS(a, b) a < b
#define LESSEQ(a, b) a <= b
#define SWAP(a , B) {Item t = a; a = b; b = t;}

Item fans[16*(int)1e5+(int)6.66];
int N;
void merge(Item *v, int l, int mid, int r);

int main(){
    int n;
    N = 0;
    int x = 0;
    while(scanf("%d", &n) != EOF){
        if(n==0) continue;
        for(int i = 0; i < n; ++i) scanf("%lli", &fans[i+N]);
        
        merge(&fans[0], 0, N-1, N+n-1);

        N += n;
    }

    printf("%lli", fans[0]);
    for(int i = 1; i < N; ++i)
        printf(" %lli", fans[i]);
    printf("\n");
    return 0;
}

void merge(Item *v, int l, int mid, int r){// [l,r]
    int pl = l;
    int pr = mid +1;
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

// AC.