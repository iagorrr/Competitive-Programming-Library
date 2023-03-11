// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(a) for(auto &x : a) cin >> x
#define all(a) a.begin(), a.end()

int H, W;
set<ll> v;
ll dfs(int x, int y, const vector<vll> &g) {
  v.insert(g[x][y]);
   
  ll ans = 0;
  
  if(x == H-1 and y == W-1) ans++;
  if(x+1 < H and !v.count(g[x+1][y])) ans += dfs(x+1, y, g);
  if(y+1 < W and !v.count(g[x][y+1])) ans += dfs(x, y+1, g);

  v.erase(g[x][y]);
  return ans;
}
void run(){
  cin >> H >> W;
  vector<vector<ll>> g(H, vll(W));
  for(int i = 0; i  < H; ++i) {
    for(int j = 0; j < W; ++j) {
      cin >> g[i][j];
    }
  }
  ll ans = dfs(0, 0, g);
  cout << ans << '\n';
}
int32_t main(void){ //fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// graph, dfs.
