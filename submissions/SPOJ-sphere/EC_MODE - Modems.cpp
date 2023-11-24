#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...) 42
#endif
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
int lg2(ll x) {
  return __builtin_clzll(1) - __builtin_clzll(x);
}

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D",
// "LD", "L"}); int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}; int
// dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll oo = 1e18;
int T(1);

struct DSU {
  vi ps, sz;

  // vector<unordered_set<int>> sts;

  DSU(int N) : ps(N + 1), sz(N, 1) /*, sts(N) */ {
    iota(all(ps), 0);
    // for (int i = 0; i < N; i++) sts[i].insert(i);
  }
  int find_set(int x) {
    return ps[x] == x ? x : ps[x] = find_set(ps[x]);
  }
  int size(int u) { return sz[find_set(u)]; }
  bool same_set(int x, int y) {
    return find_set(x) == find_set(y);
  }
  void union_set(int x, int y) {
    if (same_set(x, y)) return;

    int px = find_set(x);
    int py = find_set(y);

    if (sz[px] < sz[py]) swap(px, py);

    ps[py] = px;
    sz[px] += sz[py];
    // sts[px].merge(sts[py]);
  }
};
ll n, maxr, costr, costf, sats;
auto solve() {
  cin >> n >> maxr >> sats >> costr >> costf;

  vector<pll> points(n);
  for (auto &[x, y] : points) {
    cin >> x >> y;
  }

  // build graph
  vector<tuple<ld, int, int, bool>> edges;
  for (int i = 0; i < n; i++) {
    auto &[x1, y1] = points[i];

    for (int j = i + 1; j < n; j++) {
      auto [x2, y2] = points[j];

      ld cost = hypot(x1 - x2, y1 - y2);
      bool isOpt = false;
      if (cost <= maxr)
        cost *= costr;
      else
        cost *= costf, isOpt = true;

      edges.emplace_back(cost, i, j, isOpt);
    }
  }

  // kruskal
  DSU dsu(n);
  int components(n);
  sort(all(edges));

  ld costa, costb;
  costa = costb = 0;
  for (auto &[cost, u, v, isoptical] : edges) {
    if (components <= sats) break;
    if (dsu.same_set(u, v)) continue;

    components--;
    dsu.union_set(u, v);
    if (isoptical)
      costb += cost;
    else
      costa += cost;
  }

  return make_pair(costa, costb);
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  cin >> T;

  for (int i = 1; i <= T; i++) {
    cout << "Caso #" << i << ": ";
    auto [a, b] = solve();
    cout << fixed << setprecision(3) << a << ' ' << b
         << endl;
  }
}

/*
 * https://www.spoj.com/problems/EC_MODE/
 * graphs
 * mst
 * kruskal
 * dsu
 * greedy
 * */

