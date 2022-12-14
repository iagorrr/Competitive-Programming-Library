// iagorrr ;)
#include <stdio.h>
#include <string.h>
char S[(int)1e5 + 666];

typedef struct{
    int i;
    int p;
    char c;
} Item;
int less(Item a, Item b);
// TODO: implementar usando macro.
int less(Item a, Item b){
    return a.i == b.i ? a.p < b.p : a.i >= b.i;
}

void merge(Item *v, int l, int r){// [l,r]
    int mid = l + (r-l)/2;
    int pl = l;
    int pr = mid+1;
    int p = 0;
    Item aux[r-l+1];

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
    scanf("%s", S); // TODO: usar informação de quantos bytes o scanf leu ao invés do len;
    int n = strlen(S);

    char cur = S[0];
    int p = 0;
    Item v[(int)1e5+666];
    int nv = 0;
    for(int i = 0; i < n; ++i){
        if(cur != S[i]){
            v[nv].i = i-p;
            v[nv].c = cur;
            v[nv].p = p;
            nv++;
            // printf("%d %c %d\n", i-p, cur, p);
            p = i;
            cur = S[p];
        }

        if(i == n-1){
            // printf("%d %c %d\n", i-p+1, cur, p);
            v[nv].i = i-p+1;
            v[nv].c = cur;
            v[nv].p = p;
            nv++;
        }
    }

    merge_sort(v, 0, nv-1);
    for(int i = 0; i < nv; ++i)
        printf("%d %c %d\n", v[i].i, v[i].c, v[i].p);
    
    return 0;
}

// AC.