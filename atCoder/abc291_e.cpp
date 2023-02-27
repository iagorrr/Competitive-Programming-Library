// iagorrr ;)
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
vector<int> lowerthan(2*1e5+1, -1);
vector<char> exist(2*1e5+1, 0);
vector<unordered_set<int>> g(2*1e5+1);
int n, m;

int dfs(int x) {
  if(lowerthan[x] != -1) return lowerthan[x];
  
  lowerthan[x] = 0;
  for(auto &v : g[x])
    lowerthan[x] = max(lowerthan[x], dfs(v) + 1);

  return lowerthan[x];
}

void solve() {
  for(int i = 1; i <= n; ++i)
    lowerthan[i] = dfs(i);

  for(int i = 1; i <= n; ++i)
    exist[lowerthan[i]] = 1;

  for(int i = 0; i < n; ++i)
    if(!exist[i]) {cout << "No\n"; return;} 

  cout << "Yes\n";
  for(int i = 1; i <= n; ++i)
    cout << n-lowerthan[i] << " \n"[i==n];
}

int32_t main(void){ fastio;
  cin >> n >> m;
  for(int i = 0; i < m; ++i){
    int l, r; cin >> l >> r;
    g[l].insert(r);
  }
  solve();
}

// AC, graph, math.


