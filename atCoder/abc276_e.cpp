// iagorrr ;)
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll H, W;
ll xs, ys;
vector<string> board;
map<pair<int, int>, bool> check;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// valid a point.
bool valid(int x, int y){
    if(x >= 0 and x < H and y >= 0 and y < W and !check[{x, y}] and board[x][y] != '#') return true;

    return false;
}
// try to reach the adjacents of S going form x, y.
bool dfs(int x, int y, int m){
    //cout << "dfs: " << x << ' ' << y << '\n';
    if(x == xs and y == ys and m >= 4) return true;
    if(!valid(x, y)) return false;
    
    check[{x, y}] = true;

    for(int i = 0; i < 4; ++i){
        int x2 = x + dx[i];
        int y2 = y + dy[i];
    
        if(dfs(x2, y2, m+1)) return true;
        
    }
    return false;
}
bool solve(){
    check[{xs,ys}] = true;

    // call the dfs to the adjacents.
    for(int i = 0 ; i <4; ++i){
        int x2 = xs + dx[i];
        int y2 = ys + dy[i];

        if(valid(x2,y2)){
            if(dfs(x2, y2, 1)) return true;
        }
    }

    return false;
}
int main(){
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> H >> W;
    
    for(int i = 0; i < H; ++i){
        string s;
        cin >> s;
        for(int j = 0; j < W; ++j){
            if(s[j] == 'S'){
                xs = i;
                ys = j;
            }
        }
        board.push_back(s);
    }
    bool ans = solve();
    cout << (ans ? "Yes" : "No") << '\n';
    return 0;
}
// AC.