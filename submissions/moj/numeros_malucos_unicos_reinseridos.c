// iagorrr
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
    int p = 1;
    Item aux[r-l+1+1]; aux[0] = -__INT_MAX__;

    while(pl <= mid && pr <= r){
        if(LESSEQ(v[pl], v[pr]))
            aux[p++] = v[pl++];
        else
            aux[p++] = v[pr++];
    }

    while(pl <= mid)
        aux[p++] = v[pl++];
    while(pr <= r)
        aux[p++] = v[pr++];
    
    p = 1;
    for(int i = l; i <= r; ++i)
        v[i] = aux[p++];
}

// merge but doesn't repeat the values, return the total of repetitions.
int merge_but_dont_touch(Item *v, int l, int r, int mid){// [l,r] https://www.youtube.com/watch?v=J7aAKMzi4zw
    
    int pl = l;
    int pr = mid+1;
    int p = 1;
    Item aux[r-l+1+1]; aux[0] = -__INT_MAX__;

    int repetitions = 0;

    while(pl <= mid && pr <= r){
        if(LESSEQ(v[pl], v[pr])){
            if(p != 1 && aux[p-1] == v[pl]){// ignore the element at left.
                ++repetitions;
                ++pl;
            }
            else aux[p++] = v[pl++];
        }
        else{
            if(p != 1 && aux[p-1] == v[pr]){// guess what ?
                ++repetitions;
                ++pr;
            }
            else aux[p++] = v[pr++];
        }
    }

    while(pl <= mid){
        if(aux[p-1] == v[pl]){
            ++repetitions;
            ++pl;
        }
        else aux[p++] = v[pl++];
    }
    while(pr <= r){
        if(aux[p-1] == v[pr]){
            ++repetitions;
            ++pr;
        }
        else aux[p++] = v[pr++];
    }
    
    p = 1;
    for(int i = l; i <= r-repetitions; ++i)
        v[i] = aux[p++];

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
    // Leitura dos elementos do vetor :), tudo intervalo fechado agora.
    int n;
    scanf("%d", &n);
    Item v[2*n+2];    
    for(int i = 1; i <= n; ++i)
        scanf("%lli", &v[i]);
    
    // Ordenar o vetor de modo que tire as repetições, e adicionar o 1000000 se necessário.
    int repetitions = merge_sort(&v[0], 1, n, 1);
    n -= repetitions;
    // printf("Após ordneção e tirar repete: "); print_v(v, 1, n);
    if(n&1)
        v[++n] = (ll)1e9;
    
    // fazer as somas 2 a 2, e colocar no final do vetor.
    int tot_soma2 = 0;
    for(int i = 1; i <= n-1; i += 2)
        v[n+(++tot_soma2)] = v[i]+v[i+1];   

    // mergear e manter ordenação sem repetição do que ja tinha e das somas.
    repetitions = merge_but_dont_touch(&v[0], 1, n+tot_soma2, n);
    n+=tot_soma2;
    n -= repetitions;
    

    // exibir oque foi solicitado
    for(int i = 1; i <= n; i += 4)
        printf("%lli\n", v[i]);

    printf("Elementos: %d\n", n);
    
    return 0;
}
