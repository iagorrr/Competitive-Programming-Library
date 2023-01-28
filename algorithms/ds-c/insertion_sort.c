// iagorrr ;)
typedef int Item;

#define less(a, b) a < b
#define lesseq(a, b) a <= b
#define exchange(a , b) {Item t = a; a = b; b = t;}
#define lessexchange(a, b) {if(less(a, b) exchange(a, b))}

void insertion_sort(Item *v, int l, int r){// [l , r]
    for(int i = r; i > l; --i)
        if(v[i] > v[i-1]) exchange(v[i], v[i-1]);

    for(int i = l+1; i <= r; ++i){
        int j = i;
        int pivot = v[j];
    
        while(less(pivot, v[j-1])){
            v[j] = v[j-1];
            --j;
        }

        v[j] = pivot;
    }
}

int main(){ return 0;}
