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

const int MAXN(3 * 1'00'000);
int N;
vi2d G(MAXN);

int farthest(int s) {
  int last = s;
  queue<pii> q;
  q.emplace(s, -1);
  while (not q.empty()) {
    auto [u, p] = q.front();
    q.pop();
    last = u;
    for (auto v : G[u]) {
      if (v == p) continue;
      q.emplace(v, u);
    }
  }

  return last;
}

vi dists(int s) {
  vi ds(N);
  ds[s] = 0;
  queue<pii> q;
  q.emplace(s, -1);

  while (not q.empty()) {
    auto [u, p] = q.front();
    q.pop();

    for (auto v : G[u]) {
      if (v == p) continue;
      ds[v] = ds[u] + 1;
      q.emplace(v, u);
    }
  }

  return ds;
}
auto solve() {
  cin >> N;

  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  auto a = farthest(0);
  auto b = farthest(a);

  auto dsa = dists(a);
  auto dsb = dists(b);
  auto d = dsa[b];

  for (int i = 0; i < N; i++) {
    cout << max({d, max(dsa[i], dsb[i]) + 1}) << endl;
  }
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  int t;
  t = 1;

  // cin >> t;

  for (int i = 1; i <= t; i++) {
    solve();
  }
}

// AC, trees, bfs/dfs, diameter
