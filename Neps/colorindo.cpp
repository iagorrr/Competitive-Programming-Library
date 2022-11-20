// iagorrr ;) BFS / Flood Fill
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define MAXN 204

int n, m, x, y, k;
int figura[MAXN][MAXN];
bool visited[MAXN][MAXN];

int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

bool check(int i, int j){
    if(i <= 0 || i > n || j <= 0 || j > m) return false;
    if(visited[i][j]) return false;
    if(figura[i][j] == 1) return false;

    return true;
}
int solve(){
    int ans = 0;

    queue <pair<int, int>> bfs;
    bfs.push({x, y});
    visited[x][y] = true;
    while(!bfs.empty()){
        auto current = bfs.front(); bfs.pop();
        ans++;

        for(int i = 0 ; i < 8; ++i){
            int x2 = current.first + dx[i];
            int y2 = current.second + dy[i];

            if(check(x2, y2)){
                visited[x2][y2] = true;
                bfs.push({x2, y2});
            }
        }
    }

    return ans;
}
int main(){
    cin >> n >> m >> x >> y >> k;
    
    for(int i = 0 ; i < k; ++i){
        int x2, y2;
        cin >> x2 >> y2;
        figura[x2][y2] = 1;
    }
    
    cout << solve() << endl;
    return 0;
}

// Aceito.