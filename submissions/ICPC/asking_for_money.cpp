// iagorrr ;)
#include <algorithm>
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

string ans(1e3+1, 'N');
vector<vll> g(1e3+1);
vector<pll> canask(1e3+1);

vector<char> vis(1e3+1);
void canreach(ll c, ll p) {
  vis[c] = true;

  for(auto v : g[c])
    if(!vis[v] and v != p) canreach(v, p);
}
void solve(ll n) {
  for(int i = 1; i <= n; ++i) {
    auto [a, b] = canask[i];

    vll reached(n+1);

    vis = vector<char>(n+1, 0);
    canreach(i, i);
    for(int j = 1; j <= n; ++j) reached[j] += vis[j];


    vis = vector<char>(n+1, 0);
    canreach(a, i);
    for(int j = 1; j <= n; ++j) reached[j] += vis[j];

    vis = vector<char>(n+1, 0);
    canreach(b, i);
    for(int j = 1; j <= n; ++j) reached[j] += vis[j];

    if(*max_element(all(reached)) == 3) ans[i] = 'Y';
  }
}
void run(){
  ll n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    ll a, b; cin >> a >> b;
    /*
       reverse it so you don't need to check if    
       there is a j which can reach i, a, b. Just
       if there is a j which can be reach by i, j, b. 
       woooow
    */
    g[a].push_back(i);
    g[b].push_back(i);
    canask[i] = {a, b};
  }

  solve(n);

  for(int i = 1; i <= n; ++i)
    cout << ans[i];

  cout << '\n';
}
int32_t main(void){ //fastio;
  int t; t = 1;
    
  while(t--)
    run();
}
// AC, dfs/bfs
