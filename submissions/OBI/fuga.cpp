#include <bits/stdc++.h>

using namespace std;

bool mark[15][15];
int N, M, Xe, Ye, Xs, Ys;
int ans;
int tempAns;

bool check(int x, int y){
    return x >= 1 && x <= N && y >= 1 && y <= M && !mark[x][y] && ((x % 2 != 0) || (y % 2 != 0));
}
// dfs using backingtrack.
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void dfs(int x, int y){
    tempAns++;
    mark[x][y] = true;

    if(x == Xs && y == Ys){
        ans = max(ans, tempAns);
    }
    else{
        for(int i = 0; i < 4; i++){
            int x2 = x + dx[i];
            int y2 = y + dy[i];
            if(check(x2, y2)){
                dfs(x2, y2);
            }   
        }
    }
    mark[x][y] = false;
    tempAns--;
}

int main(){

    cin >> N >> M;
    cin >> Xe >> Ye;
    cin >> Xs >> Ys;

    dfs(Xe, Ye);
    cout << ans << endl;
}

// 100/100.
