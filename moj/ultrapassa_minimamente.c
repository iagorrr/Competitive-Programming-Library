// iagorrr ;)
#include <stdio.h>
#define ll long long

void ultrapasseitor(ll *V, int P, ll S, const ll M, const ll N){
    if(P == N) return;

    // ultrapassei, chamar pro prox elemento e printar ao final.
    if(S + V[P] > M){
        ultrapasseitor(V, P+1, 0, M, N);
        printf("%lli\n", V[P]);
    }
    else // so continua a soma.
        ultrapasseitor(V, P+1, S+ V[P], M, N);
    
}

int main(){
    ll x;
    ll A[(int)1e5+66];
    int p = 0;
    while(scanf("%lli", &x) != EOF){
        if(x == 0) break;
        A[p++] = x;
    }
    ll S;
    scanf("%lli", &S);

    ultrapasseitor(A, 0, 0, S, p);
    return 0;
}

// AC.