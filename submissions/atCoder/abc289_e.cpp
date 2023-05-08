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

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }


int solve(int n, vector<vi> g, vi c) {
  // bfs.
  // takahashi and aioki.
  queue <array<int ,3>> q;
  q.push(array<int, 3>{0, 0, n-1});
  
  set<pii> check;
  while(!q.empty()) {
    array<int, 3> temp = q.front(); q.pop();
    int m = temp[0];
    int t = temp[1];
    int a = temp[2];

    if(t == n-1 and a == 0) return m;
    
    for(auto vt : g[t]) {
      for(auto va : g[a]) {
        if(c[vt] != c[va] and !check.count({vt, va})) {
          check.insert({vt, va});
          q.push(array<int, 3>{m+1, vt, va});
        }
      }
    }
  }

  return -1;
}
void run(){
  int n, m; cin >> n >> m;
  vi c(n); INV(c);
  
  vector<vi> g(n);
  for(int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  cout << solve(n, g, c) << '\n';

}
int32_t main(void){ fastio;
  int t; t = 1;
  cin >> t;  
  while(t--)
    run();
}
