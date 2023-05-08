// iagorrr ;)
#include <stdio.h>
#define ll long long

ll V[99999+(int)6.66];

struct Item{
    int t;
    int id;
};
typedef struct Item Item;

#define LESSEQ(A, B) (A.t == B.t ? A.id <= B.id : A.t <= B.t)
#define SWAP(A, B) {Item t = A; A = B; B = A;}

void merge(Item *v, int l, int r);
void merge_sort(Item *v, int l , int r);

// verifica dos votos de id l até r os primeiros t maiores.
void get_result_votos(int l, int r, int t)
{   
    Item votados[99999+(int)6.66];
    int totalVotados = 0;
    ll totalVotos = 0;
    for(int i = l; i <= r; ++i){
        if(V[i] > 0){
            votados[totalVotados].t = V[i];
            votados[totalVotados].id = i;
            ++totalVotados;
            totalVotos += V[i];
        }
    }

    merge_sort(votados, 0, totalVotados-1);// ordenar baseado nos votos.

    if(t == -1){// presidas.
        if(votados[0].t < totalVotos/2 + 1){
            printf("Segundo turno\n");
        }
        else{
            printf("%lli\n", votados[0].id);
        }

    }
    else{
        printf("%i", votados[0].id);
        for(int i = 1; i < t; ++i){
            printf(" %i", votados[i].id);
        }
        printf("\n");
    }
}
int main()
{
    ll S, F, E;
    scanf("%lli %lli %lli", &S, &F, &E);

    int v;
    ll tvv = 0;
    ll tvi = 0;
    while(scanf("%i", &v) != EOF){

        // total votos válidos e inválidos.
        tvv +=  v >= 0 ? 1 : 0;
        tvi +=  v >= 0 ? 0 : 1;

        // Computar todos os votos de todos os candidatos.
        if(v>=0) V[v]++;
    }

    // total votos válidos e inválidos.
    printf("%lli %lli\n", tvv, tvi);

    get_result_votos(10, 99, -1);
    get_result_votos(100, 999, S);  
    get_result_votos(1000, 9999, F); 
    get_result_votos(10000, 99999, E); 
    return 0;
}

void merge(Item *v, int l, int r){// [l,r]
    int mid = l + (r-l)/2;
    int pl = l;
    int pr = mid+1;
    int p = 0;
    Item aux[r-l+1];

    while(pl <= mid && pr <= r){
        if(!LESSEQ(v[pl], v[pr]))
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
// AC.