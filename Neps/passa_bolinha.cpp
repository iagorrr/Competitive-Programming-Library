#include <bits/stdc++.h>

using namespace std;

// Declarar fora para poder acessar.
vector <vector<int>> matriz;

// Cordenadas como chave e bool como verificação.
map <pair<int, int>,bool> jafoi;

int totalLevantados;
// Mais fácil do que usar todos aquels if.
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void dfs(int x, int y, int N){
    totalLevantados++;
    jafoi[{x,y}] = true;

    int x2, y2;
    for(int d = 0; d < 4; d++){
        x2 = x + dx[d];
        y2 = y + dy[d];

        /*
            Sempre verifica:
                Posicao valida para menos e mais
                Se atende a condição, nesse caso ser maior ou igual ao enviado.
        */
        if(0 <= min(x2,y2) && N > max(x2,y2) && !jafoi[{x2,y2}] && matriz[x2][y2] >= matriz[x][y])
            dfs(x2,y2,N);

    }
}
int main() {

    // Tamanho da matriz.
    int N;
    cin >> N;

    // Cordenadas de início.
    int sy, sx;
    cin >> sx >> sy;
    sx--;
    sy--;

    // 'realocar' o tamanho da matriz.
    matriz = vector <vector<int>>(N, vector<int>(N));

    // Receber valores da matriz
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> matriz[i][j];
        

    // Contar os virados.
    totalLevantados = 0;
    dfs(sx, sy, N);


    // Resultado !!!!
    cout << totalLevantados << endl;
    return 0;
}

// Accepted
