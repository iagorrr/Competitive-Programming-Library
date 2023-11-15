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
const int MAXN(2 * 1'00'000);
int height[MAXN];
ll xs[MAXN];
vi G[MAXN];
pii ES[MAXN];
int N, Q;

void dfs1(int u = 0, int p = -1, int hi = 1) {
  height[u] = hi;

  for (auto v : G[u]) {
    if (v == p) continue;
    dfs1(v, u, hi + 1);
  }
}

void dfs2(int u = 0, int p = -1) {
  for (auto v : G[u]) {
    if (v == p) continue;
    xs[v] += xs[u];
    dfs2(v, u);
  }
}

auto solve() {
  cin >> N;

  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
    ES[i] = {a, b};
  }

  dfs1();

  cin >> Q;

  while (Q--) {
    ll ti, ei, xi;
    cin >> ti >> ei >> xi;
    ei--;
    int a = ES[ei].first;
    int b = ES[ei].second;
    int ha = height[a];
    int hb = height[b];
    int t;
    if (ti == 1) {
      if (ha < hb)
        xs[b] -= xi, xs[0] += xi;
      else
        xs[a] += xi;
    } else {
      if (hb < ha)
        xs[0] += xi, xs[a] -= xi;
      else
        xs[b] += xi;
    }
  }

  dfs2();
  for (int i = 0; i < N; i++) {
    cout << xs[i] << endl;
  }
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

// AC, trees, dfs
