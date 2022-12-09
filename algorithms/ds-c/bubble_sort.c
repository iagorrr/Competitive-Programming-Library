// iagorrr ;)
typedef int Item;

#define LESS(a, b) a < b
#define LESSEQ(a, b) a <= b
#define SWAP(a , b) {Item t = a; a = b; b = t;}

void bubble_sort(Item *v, int l , int r){// [l, r[
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < r; ++i)
            if(LESS(v[i], v[j]))
                SWAP(v[i], v[j]);
}
