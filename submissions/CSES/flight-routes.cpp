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

vector<priority_queue<ll>> dijkstra(const vector<vector<pll>> &g, int n, int s,
                                    int k) {
  priority_queue<pll, vector<pll>, greater<pll>> pq;

  vector<priority_queue<ll>> dist(n);
  dist[0].emplace(0);
  // for (int i = 1; i < n; i++) dist[0].emplace(oo);
  pq.emplace(0, s);
  while (!pq.empty()) {
    auto [d1, v] = pq.top();
    // cout << d1 << ' ' << v << endl;
    pq.pop();

    if (not dist[v].empty() and dist[v].top() < d1) continue;

    for (auto [d2, u] : g[v]) {
      if (len(dist[u]) < k) {
        pq.emplace(d2 + d1, u);
        dist[u].emplace(d2 + d1);
      } else {
        if (dist[u].top() > d1 + d2) {
          dist[u].pop();
          dist[u].emplace(d1 + d2);
          pq.emplace(d2 + d1, u);
        }
      }
    }
  }
  return dist;
}
void run() {
  int n, m, k;
  cin >> n >> m >> k;
  adj g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--, b--;
    g[a].emplace_back(c, b);
  }

  auto dists = dijkstra(g, n, 0, k);
  // cout << "Out of dijkstra !\n";
  vll ans;
  while (not dists[n - 1].empty()) {
    ans.emplace_back(dists[n - 1].top());
    dists[n - 1].pop();
  }
  reverse(all(ans));
  for (auto &ansi : ans) cout << ansi << ' ';
  cout << endl;
}

int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, graphs, dijkstra
