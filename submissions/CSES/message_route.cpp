// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define rep(i, l, r) for (int i = (l); i < (r); i++)
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

vll reconstruct(const vll &parent, ll n) {
  vll ans;
  ll cur = n;
  ans.push_back(n);
  do {
    cur = parent[cur];
    ans.push_back(cur);
  } while (cur != 1);

  reverse(all(ans));
  return ans;
}
void run() {
  ll n, m;
  cin >> n >> m;
  vector<vll> adj(n + 1);
  for (int i = 1; i <= m; ++i) {
    ll u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  queue<pair<ll, ll>> q;
  vector<char> vis(n + 1);
  vector<ll> parent(n + 1);
  q.push({1, 0});
  bool found = false;
  vis[1] = true;
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    if (cur.first == n) {
      found = true;
    }
    for (auto u : adj[cur.first]) {
      if (!vis[u]) {
        parent[u] = cur.first;
        q.push({u, cur.second + 1});
        vis[u] = true;
      }
    }
  }

  if (found) {
    vll ans = reconstruct(parent, n);
    cout << ans.size() << '\n';
    for (auto xi : ans) {
      cout << xi << ' ';
    }
    cout << '\n';
  } else
    cout << "IMPOSSIBLE\n";
}

int32_t main(void) {
  // fastio;
  int t;
  t = 1;

  while (t--)
    run();
}
// AC, graph, reconstuct path
