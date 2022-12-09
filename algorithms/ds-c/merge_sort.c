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

    if(l >= r) return;

    int mid = l + (r-l)/2;
    
    merge_sort(v, l, mid);
    merge_sort(v, mid+1 ,r);

    merge(v, l, r);
}

int binary_search(Item *v, int l, int r, int x){
    while(l + 1 < r){
        int mid = l + (r-l)/2;
        if(LESSEQ(v[mid], x)) l = mid;
        else r = mid;
    }
    return l;
}