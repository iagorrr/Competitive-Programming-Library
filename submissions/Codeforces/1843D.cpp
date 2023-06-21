// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(xxxx)                                                              \
  for (auto &xxx : xxxx)                                                       \
    cin >> xxx;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first

void dbg_out() { cerr << endl; }
template <typename H, typename... T> void dbg_out(H h, T... t) {
  cerr << ' ' << h;
  dbg_out(t...);
}
#define dbg(...)                                                               \
  {                                                                            \
    cerr << #__VA_ARGS__ << ':';                                               \
    dbg_out(__VA_ARGS__);                                                      \
  }

ll leafs(vector<vll> &tree, ll u, vector<ll> &leafsv, vector<char> &vis) {
  vis[u] = true;
  leafsv[u] = 0;
  for (auto v : tree[u]) {
    if(!vis[v])
      leafsv[u] += leafs(tree, v, leafsv, vis);
  }
  if(leafsv[u] == 0) leafsv[u] = 1;
  return leafsv[u];
}
void run() {
  ll n;
  cin >> n;
  vector<vll> tree(n);
  for (int i = 0; i < n - 1; ++i) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  vector<ll> leafsv(n);
  vector<char> vis(n, false);
  leafs(tree, 0, leafsv, vis);
  ll q;
  cin >> q;
  while (q--) {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    ll ans = leafsv[u] * leafsv[v];
    cout << ans << '\n';
  }
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  cin >> t;
  while (t--)
    run();
}

// AC, trees
