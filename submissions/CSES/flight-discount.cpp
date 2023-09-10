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

const ll oo = 1e9 * 1e5 + 1;
using adj = vector<vector<pll>>;
pair<vll, vll> dijkstra(const adj &g, int n, int s) {
  using info = array<ll, 3>;
  priority_queue<info, vector<info>, greater<info>> pq;
  vll dist(n, oo);
  vll dist2(n, oo);  // distance that used cupon
  pq.push({0, s, 0});
  pq.push({0, s, 1});
  dist[s] = 0;
  dist2[s] = 0;
  while (!pq.empty()) {
    auto [d1, v, disco] = pq.top();
    pq.pop();
    if (disco and dist2[v] < d1) continue;
    if (not disco and dist[v] < d1) continue;

    for (auto [d2, u] : g[v]) {
      if (disco) {
        if (dist2[u] > d1 + d2) {
          dist2[u] = d1 + d2;
          pq.push({dist2[u], u, 1});
        }
      } else {
        if (dist[u] > d1 + d2) {
          dist[u] = d1 + d2;
          pq.push({dist[u], u, 0});
        }
        if (dist2[u] > d1 + d2 / 2) {
          dist2[u] = d1 + d2 / 2;
          pq.push({dist2[u], u, 1});
        }
      }
    }
  }
  return {dist, dist2};
}

void run() {
  int n, m;
  cin >> n >> m;
  adj g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--, b--;
    g[a].emplace_back(c, b);
  }

  auto [d1, d2] = dijkstra(g, n, 0);
  cout << min(d1[n - 1], d2[n - 1]) << endl;
}

int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, graphs, dijkstra
