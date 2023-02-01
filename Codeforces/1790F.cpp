// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
#define minpq  priority_queue<ll, vll, greater<ll>()>
int ans;

void dfs(vector<vector<int>> &g, vector<int> &d, vector<bool> &b, int v, int p){
    if(d[v] >= ans) return; // not possible to get a better answer from now.

    if(b[v]) ans = min(ans, d[v]); // it's a black one, and not greater than one, take it.

    for(auto u : g[v]){
        if(u == p) continue; // ignore the one who called the dfs.
        if(d[v] + 1 < d[u]){ // our distance is better than what the neighbor have.
            d[u] = d[v] + 1;
            dfs(g, d, b, u, v);
        } else ans = min(ans, d[u]+d[v]+1); // our neighbor have a better distance, take ours +1 and his distance.
    }
}
void solve(vector<vector<int>> &g, vector<int> &d, vector<bool> &b, vector<int> &c, int n){
    ans = INT_MAX;
    d[c[0]] = 0; // first black.

    dfs(g, d, b, c[0], -1);

    b[c[0]] = true; 

    for(int i = 1; i < n; ++i){
        d[c[i]] = 0; // colored !
        dfs(g, d, b, c[i], -1); // update the the distances.
        b[c[i]] = true; // colored, and updated.
        cout << ans << ' ';
    }
    cout << '\n';
}

//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
int32_t main(void){ // fastio;
    int t; cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> c(n+1);
        for(int i = 0; i < n; ++i){ cin >> c[i]; c[i]--;}

        vector<vector<int>> g(n+1); // graph
        vector<int> d(n+1, INT_MAX); // dist to the closest black
        vector<bool> b(n+1, false); // black or not

        for(int i = 0; i < n-1; ++i){
            int u, v; cin >> u >> v;
            --v; --u;
            g[u].push_back(v); g[v].push_back(u);
        }

        solve(g, d, b, c, n);
    }
}

// AC 
