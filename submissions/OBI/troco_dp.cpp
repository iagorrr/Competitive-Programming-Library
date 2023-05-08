// iagorrr
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check[1000+4][100000+4];
int s, n;
char ans = 'N';
int moedas[1000+4];

void busca(int moeda, int soma){
    if(check[moeda][soma]) return;
    check[moeda][soma] = true;

    // Achamos o valor que buscavamos.
    if(soma == s){
        ans = 'S';
        return;
    }

    // Não é mais possível adicionar moedas nessa soma.
    if(soma > s) return;

    // Já olhamos todas as moedas.
    if(moeda >= n) return;

    // Checar adicionando a moeda.
    busca(moeda+1, soma+moedas[moeda]);

    // Checar ignorando essa moeda.
    busca(moeda+1, soma);
}

int main(){
    cin >> s >> n;
    for(int i = 0; i < n; ++i) cin >> moedas[i];

    busca(0,0);

    cout << ans << endl;
    return 0;
}

// 70/100 na OBI 100/100 no neps