// iagorrr ;) Flood-Fill BFS
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, m;
int salao[15][15];
bool visited[15][15];
int x, y;

/*
    0 - sem cristal, saída.
    1 - sem cristal, sem saída.
    2 - parede de cristal.
    3 - posicao inicial do doende.
*/
bool check(int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= m) return false;
    if(visited[x][y]) return false;
    if(salao[x][y] == 2) return false;

    return true;
}

struct no{
    int x;
    int y;
    int moves;
};
typedef struct no no;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int solve(){
    int ans = INT_MAX;
    
    queue<no> bfs;
    no inicial;
    inicial.x = x; inicial.y = y; inicial.moves = 0;
    bfs.push(inicial);
    visited[x][y] = true;

    while(!bfs.empty()){
        no atual = bfs.front(); bfs.pop();

        if(salao[atual.x][atual.y] == 0){
            ans = min(ans, atual.moves);
            continue;
        }

        for(int i = 0; i < 4; ++i){
            int x2 = atual.x + dx[i];
            int y2 = atual.y + dy[i];
            int moves2 = atual.moves+1;
            if(check(x2, y2)){
                visited[x2][y2] = true;
                no temp; temp.x = x2, temp.y = y2, temp.moves = moves2;
                bfs.push(temp);
            }
        }

    }



    return ans;
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> salao[i][j];
            if(salao[i][j]==3){
                x = i;
                y = j;
            }
        }
    }

    cout << solve() << endl;

    return 0;
}

// Accepted.
