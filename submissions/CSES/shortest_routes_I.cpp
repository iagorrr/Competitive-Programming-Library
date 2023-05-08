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
 
void dijkstra(const vector<vector<pll>> &g, vll &dist) {
  priority_queue<pll, vector<pll>, greater<pll>> pq;
 
  pq.emplace(0, 0);
  dist[0] = 0;
  while(!pq.empty()){
    auto [d1, v] = pq.top(); pq.pop();
    
    for (auto [d2, u] : g[v]) {
      if(dist[u] > d1 + d2) {
        dist[u] = d1 + d2;
        pq.push({dist[u], u});
      }
    }
  }
} 
void run(){
  ll n, m; cin >> n >> m;
  vector<vector<pll>> g(n);
  for(int i = 0; i < m; ++i) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    g[a].emplace_back(c, b);
  }
 
  vll dist(n, LLONG_MAX);
  dijkstra(g, dist);
  for(auto x : dist) {
    cout << x << ' ';
  }
  cout << '\n';
}
 
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}
