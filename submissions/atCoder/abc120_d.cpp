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
  vi ps;
  vi sz;
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
ll nfirst(ll n) { return (n * (n + 1ll)) / 2ll; }

int n, m;
vi2d g;
vector<pii> es;
auto solve() {
  cin >> n >> m;
  g.resize(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    es.emplace_back(u, v);
  }

  ll cur = nfirst(n - 1);
  DSU dsu(n);
  vll ans;
  for (auto it = es.rbegin(); it != es.rend(); it++) {
    ans.emplace_back(cur);
    auto [u, v] = *it;

    if (not dsu.same_set(u, v)) {
      cur -= dsu.size(u) * dsu.size(v);
    }

    dsu.union_set(u, v);
  }

  for (auto it = ans.rbegin(); it != ans.rend(); it++) {
    cout << *it << endl;
  }
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> T;

  for (int i = 1; i <= T; i++) {
    solve();
  }
}
/*
 * https://atcoder.jp/contests/abc120/tasks/abc120_d
 * graphs
 * connected components
 * dsu
 * */
