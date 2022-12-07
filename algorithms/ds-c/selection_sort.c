// iagorrr ;)
#include <stdio.h>
typedef int Item;
#define LESS(A, B) A < B
#define SWAP(A,B){ Item AUX = A; A = B; B = AUX;}
void selection_sort(Item *v, int l, int r){
    for(int i = l; i <= r; ++i){
        int min = i;
        for(int j = i + 1; j <= r; ++j)
           if(LESS(v[j], v[min])) min = j;
        
        SWAP(v[min], v[i])
    }
}
