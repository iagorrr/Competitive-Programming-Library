#include <bits/stdc++.h>

using namespace std;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N, F;
    cin >> N >> F;
    F = F+'0';

    vector <string> terreno(N);
    for(int i = 0; i < N; i++) cin >> terreno[i];

    // Primeira posição vai ser invadida pela lava.
    queue <pair<int, int>> spread;
    if(terreno[0][0] <= F){
        terreno[0][0] = '*';
        spread.push({0, 0});
    }

    while(!spread.empty()){
        auto atual = spread.front();
        spread.pop();

        int x, y;
        y = atual.first;
        x = atual.second;

        // Verificar as quatro posições ortogonais.
        for(int i = 0; i < 4; i++){
            int x2 = x + dx[i];
            int y2 = y + dy[i];

            if(min(x2, y2) >= 0 && max(x2, y2) <= N-1){
                if(terreno[y2][x2] <= F && terreno[y2][x2]!= '*'){
                    terreno[y2][x2] = '*';
                    spread.push({y2, x2});
                }
            }

        }
    }

    for(int i = 0; i < N; i++) cout << terreno[i] << endl;

} 

// 100/100
