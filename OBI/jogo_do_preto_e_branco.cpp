// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
/*
    -1 -> vazio
    0 -> branco
    1 -> preto.
*/
int tab[8][8];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// função para verificar se é válido inserir em uma dada cordenada.
bool check(const int i, const int  j, const int l, const int c){
    // a célula não está vazia.
    if(tab[i][j] != -1) return false;

    // verificar se não tem nem uma peça branca adjacente.
    for(int k = 0; k < 4; ++k){
        int i2 = i + dx[k];
        int j2 = j + dy[k];

        if(tab[i2][j2] == 0) return false;
    }

    return true;
}
int main(){
    memset(tab, -1, sizeof(tab));

    int l, c;
    cin >> l >> c;

    int p;
    cin >> p;

    for(int i = 1; i <= p; ++i){
        int x, y;
        cin >> x >> y;
        tab[x][y] = 1;
    }

    // inserir em toda posição posível.
    for(int i = 1; i <= l; ++i){
        for(int j = 1; j <= c; ++j){

            if(tab[i][j] == 1){
                for(int k = 0; k < 4; ++k){
                    int i2 = i + dx[k];
                    int j2 = j + dy[k];

                    if(check(i2, j2, l, c)) tab[i2][j2] = 0;
                }
            }
        }
    }

    // contar quantas brancas existem.
    int ans = 0;
    for(int i = 1; i <= l; ++i){
        for(int j = 1; j <= c; ++j)
            if(tab[i][j] == 0) ans++;
        
    }
    cout << ans << '\n';
    return 0;
}

// 80/100 WA.