// iagorrr ;)
typedef int Item;

#define LESS(a, b) a < b
#define LESSEQ(a, b) a <= b
#define SWAP(a , b) {Item t = a; a = b; b = t;}


void insertion_sort(Item *v, int l, int r){// [l , r[
    for(int i = r-1; i > l; --i)
        if(v[i] > v[i-1]) SWAP(v[i], v[i-1]);

    for(int i = l+1; i < r; ++i){
        int j = i;
        int t = v[j];
    
        while(t <= v[j-1]){
            v[j] = v[j-1];
            --j;
        }
        v[j] = t;
    }
}