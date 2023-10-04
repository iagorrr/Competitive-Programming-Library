#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int)__x.size()
using ll = long long;
using ull = unsigned long long;
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
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

vector<string> dir({"LU", "U", "RU", "R", "RD", "D", "LD", "L"});
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int oo = 1'000'000 * 300 + 1;
const int MAXN(300);
int N, M;
vector<pii> g[MAXN];
vi2d dist1(MAXN, vi(MAXN, oo));
vi2d dist2(MAXN, vi(MAXN, oo));

void floyd_warshall() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        dist2[j][k] = min(dist2[j][k], dist2[j][i] + dist2[i][k]);
      }
    }
  }
}

vi d(MAXN);
int dijkstra(int s, int e) {
  fill(all(d), oo);
  d[s] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.emplace(0, s);

  while (not pq.empty()) {
    auto [du, u] = pq.top();
    pq.pop();
    if (u == e) return d[e];
    if (du > d[u]) continue;

    for (auto &[v, dv] : g[u]) {
      if ((u == s and v == e) or (u == e and v == s)) continue;
      if (dv + du < d[v]) {
        d[v] = dv + du;
        pq.emplace(d[v], v);
      }
    }
  }

  return d[e];
}
auto solve() {
  cin >> N >> M;

  vector<pii> es;
  while (M--) {
    int u, v, l;
    cin >> u >> v >> l;
    u--, v--;
    dist1[u][u] = 0;
    dist1[v][v] = 0;
    dist1[u][v] = min(dist1[u][v], l);
    dist1[v][u] = min(dist1[v][u], l);

    dist2[u][u] = 0;
    dist2[v][v] = 0;
    dist2[u][v] = min(dist2[u][v], l);
    dist2[v][u] = min(dist2[v][u], l);
    g[u].emplace_back(v, l);
    g[v].emplace_back(u, l);
    es.emplace_back(u, v);
  }

  floyd_warshall();
  for (auto [u, v] : es) {
    int ans = oo;
    if (dist2[u][v] < dist1[u][v])
      ans = dist2[u][v];
    else
      ans = dijkstra(u, v);

    cout << (ans == oo ? -1 : ans) << endl;
  }
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) solve();
}

// AC, floyd warshall, dijkstra
