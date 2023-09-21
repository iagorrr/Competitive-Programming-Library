#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int)__x.size()
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

const ll INF = 1000000000;

vll dijkstra(vector<vector<pll>> &adj, int s, int s2) {
  int n = len(adj);
  vll d(n + 1, INF);

  d[s] = 0;
  set<pair<int, int>> q;
  q.insert({0, s});
  while (!q.empty()) {
    int v = q.begin()->second;
    q.erase(q.begin());

    for (auto edge : adj[v]) {
      ll to = edge.second;
      ll len = edge.first;
      if (v == s and to == s2) continue;
      if (v == s2 and to == s) continue;
      if (d[v] + len < d[to]) {
        q.erase({d[to], to});
        d[to] = d[v] + len;
        q.insert({d[to], to});
      }
    }
  }
  return d;
}
void run() {
  int n, m;
  cin >> n >> m;

  vector<vector<pll>> g(n + 1);
  vector<array<ll, 3>> q;
  for (int i = 0; i < m; i++) {
    int u, v;
    ll l;
    cin >> u >> v >> l;
    g[u].emplace_back(l, v);
    g[v].emplace_back(l, u);

    q.push_back({u, v, l});
  }

  vll2d dists(n + 1, vll(n + 1, INF));
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      auto dist = dijkstra(g, i, j);
      dists[i][j] = dist[j];
      dists[j][i] = dist[j];
    }
  }

  for (auto &[u, v, l] : q) {
    if (u > v) swap(u, v);
    cout << (dists[u][v] == INF ? -1 : dists[u][v]) << endl;
  }
}
int32_t main(void) {
  // fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}
