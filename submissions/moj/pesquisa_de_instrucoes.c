// iagorrr ;)
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char c[20];
} Item;

#define LESS(a, b) a.id < b.id
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

    if(l >= r) return;

    int mid = l + (r-l)/2;
    
    merge_sort(v, l, mid);
    merge_sort(v, mid+1 ,r);

    merge(v, l, r);
}

int binary_search(Item *v, int l, int r, int x){
    while(l + 1 < r){
        int mid = l + (r-l)/2;
        if(LESSEQ(v[mid].id, x)) l = mid;
        else r = mid;
    }
    return l;
}
int main(){
    int n;
    scanf("%d", &n);

    Item v[n];
    for(int i = 0; i < n; ++i)
        scanf("%d %s", &v[i].id, v[i].c);
    
    merge_sort(&v[0], 0, n-1);
    
    int id;
    while(scanf("%d", &id) != EOF){
        int ans = binary_search(&v[0], 0, n, id);
        printf("%s\n", v[ans].id == id  ? v[ans].c : "undefined");
    }
    
    return 0;
}

// AC.