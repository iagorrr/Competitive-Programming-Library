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

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D",
// "LD", "L"}); int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}; int
// dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll oo = 1e18;
int T(1);
ll N, M, K;

struct DSU {
  vi ps;
  vi size;
  DSU(int _n) : ps(_n + 1), size(_n, 1) {
    iota(all(ps), 0);
  }
  int find_set(int x) {
    return ps[x] == x ? x : ps[x] = find_set(ps[x]);
  }
  bool same_set(int x, int y) {
    return find_set(x) == find_set(y);
  }
  void union_set(int x, int y) {
    if (same_set(x, y)) return;

    int px = find_set(x);
    int py = find_set(y);

    if (size[px] < size[py]) swap(px, py);

    ps[py] = px;
    size[px] += size[py];
  }
};
vector<array<ll, 3>> E;
auto solve() {
  cin >> N >> M >> K;

  for (int i = 0; i < M; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    E.push_back({u, v, w});
  }

  // dbg(E);

  ll ans = oo;
  vi choose(M);
  for (int i = 0; i < N - 1; i++) choose[i] = 1;
  sort(all(choose));
  // dbg(choose);
  do {
    DSU dsu(N);
    ll cost = 0;
    for (int i = 0; i < M; i++) {
      if (not choose[i]) continue;
      int u = E[i][0];
      int v = E[i][1];
      cost += E[i][2];
      // if (u >= N or v >= N) dbg(u, v);
      dsu.union_set(u, v);
    }
    bool ok = false;
    for (int i = 0; i < N; i++) ok |= dsu.size[i] == N;
    if (ok) ans = min(ans, cost % K);
  } while (next_permutation(all(choose)));

  cout << ans << endl;
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> t;

  for (int i = 1; i <= T; i++) {
    solve();
  }
}

// AC, graphs, trees, MST, DSU, combinatorics
