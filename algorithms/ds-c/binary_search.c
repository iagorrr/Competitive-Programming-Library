typedef int Item;

#define LESS(a, b) a < b
#define LESSEQ(a, b) a <= b
#define SWAP(a , B) {Item t = a; a = b; b = t;}

int binary_search(Item *v, int l, int r, int x){
    while(l + 1 < r){
        int mid = l + (r-l)/2;
        if(LESSEQ(v[mid], x)) l = mid;
        else r = mid;
    }
    return l;
}