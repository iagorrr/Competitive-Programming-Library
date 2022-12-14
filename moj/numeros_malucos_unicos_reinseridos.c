// iagorrr ;) :( :(  :( :( :( :( :( :( :(
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
typedef ll Item;

#define LESS(a, b) a < b
#define LESSEQ(a, b) a <= b
#define SWAP(a , B) {Item t = a; a = b; b = t;}


void merge(Item *v, int l,int r){// [l,r]
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

// merge but doesn't repeat the values, return the total of repetitions.
int merge_but_dont_touch(Item *v, int l, int r, int mid){// [l,r]
    
    int pl = l;
    int pr = mid+1;
    int p = 0;
    Item aux[r-l+1];

    int repetitions = 0;

    // printf("first half: \n");
    // for(int i = 0; i <= mid; ++i) printf("%lli ", v[i]);
    // printf("\n");


    // printf("second half: \n");
    // for(int i = mid+1; i <= r; ++i) printf("%lli ", v[i]);
    // printf("\n");

    while(pl <= mid && pr <= r){
        // printf("aux[%d] = %lli v[%d] = %lli v[%d] = %lli\n", p, aux[p], pl, v[pl], pr, v[pr]);
        if(LESS(v[pl], v[pr])){
            if(p != 0 && aux[p-1] == v[pl]){// ignore the element at left.
                // printf("r\n");
                ++repetitions;
                ++pl;
            }
            else aux[p++] = v[pl++];
        }
        else{
            if(p != 0 && aux[p] == v[pr]){// guess what ?
                // printf("r\n");
                ++repetitions;
                ++pr;
            }
            else aux[p++] = v[pr++];
        }
    }

    while(pl <= mid){
        if(aux[p] == v[pl]){
            // printf("r\n");
            ++repetitions;
            ++pl;
        }
        else aux[p++] = v[pl++];
    }
    while(pr <= r){
        if(aux[p] == v[pr]){
            // printf("r\n");
            ++repetitions;
            ++pr;
        }
        else aux[p++] = v[pr++];
    }
    
    p = 0;
    for(int i = l; i <= r-repetitions; ++i)
        v[i] = aux[p++];

    // printf("repetitions from merge: %d\n", repetitions);
    return repetitions;
}


int merge_sort(Item *v, int l , int r, int first){// [l, r]
    // unitary vector.
    if(l >= r) return 0;

    int mid = l + (r-l)/2;
    // sort first and second half.
    merge_sort(v, l, mid, 0);
    merge_sort(v, mid+1 ,r, 0);

    // with both sorted just merge it, if is the final merge, MERGE BUT DON'T TOUCH.
    if(first)
        return merge_but_dont_touch(v, l, r, mid);
    else
        merge(v, l, r);

    return 0;
}

int main(){
    // Leitura dos elementos do vetor :)
    int n;
    scanf("%d", &n);
    Item v[2*n];    
    for(int i = 0; i < n; ++i)
        scanf("%lli", &v[i]);
    
    // Ordenar o vetor de modo que tire as repetições, e adicionar o 1000000 se necessário.
    int repetitions = merge_sort(&v[0], 0, n-1, 1);
    n -= repetitions;
    if(n&1){
        v[n] = (int)1e6;
        n++;
    }
    // printf("Repetitions : %d\n", repetitions);
    // printf("New vector: ");
    // for(int i = 0 ; i < n; ++i) printf("%lli ", v[i]);
    // printf("\n");

    // printf("Sum2: ");
    int preguica = 0;
    for(int i = 0; i*2 < n-1; ++i){
        v[i+n] = v[i*2]+v[(i*2)+1];
        // printf("%lli ", v[i+n]);
        ++preguica;
    }
    // printf("\n");
    n += preguica;

    // printf("New vector sum2: ");
    // for(int i = 0 ; i < n; ++i) printf("%lli ", v[i]);
    // printf("\n");

    
    repetitions = merge_sort(&v[0], 0, n-1, 1);
    // printf("Repetitions : %d\n", repetitions);
    n -= repetitions;
    // printf("New vector: ");
    // for(int i = 0 ; i < n; ++i) printf("%lli ", v[i]);
    // printf("\n");


    // printf("\n\n\n\n\n");
    // pegar de 4 em 4.
    for(int i = 0; i < n; i += 4)
        printf("%lli\n", v[i]);

    printf("Elementos: %d\n", n);
    
    
    
    return 0;
}
