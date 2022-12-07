// iagorrr ;)
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
bool valid(int i, int j, int n){
    return i >= 1 and i <= n and j >= 1 and j <= n;
}
// bfs to find the mnimum moves necessary to reach each grid position.
vector<vector<int>> ans(466, vector<int>(466, -1));
void solve(int n, int m){

    // get all valid variations that the 'distance' match m.
    vector<pair<int, int>> delta;
    int sqrtm = (int)ceil(sqrt(m));
    for(int i = -sqrtm; i <= sqrtm; ++i){
        for(int j = -sqrtm; j <= sqrtm; ++j){
            if(i*i + j*j == m) delta.emplace_back(i, j);
        }
    }

    queue<pair<int,int>> q;
    q.push({1, 1});
    ans[1][1] = 0;
    while(!q.empty()){
        auto [k, l] = q.front(); q.pop();
        // if we know the valid i,j the valid positions from k,l is k+i, k+j... 
        for( auto [dk, dj] : delta){
            int ddk = k + dk, ddj = l + dj;
            if(valid(ddk, ddj, n) and ans[ddk][ddj] == -1){// ivalid position and not visited yet.
                q.push({ddk,ddj});
                ans[ddk][ddj] = ans[k][l] + 1;
            }
        }
    }

}

int32_t main(){ 

    fastio
    int n, m;
    cin >> n >> m;

    solve(n, m);

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
// AC
