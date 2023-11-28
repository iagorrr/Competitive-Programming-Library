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
int N, M;
vector<char> VIS;
vi2d G;

void dfs(int u) {
  VIS[u] = 1;
  for (auto v : G[u]) {
    if (VIS[v]) continue;
    dfs(v);
  }
}
auto solve() {
  cin >> N >> M;
  G.resize(N);
  VIS.resize(N);

  while (M--) {
    int u, v, _;
    cin >> u >> v >> _;
    u--, v--;
    G[u].emplace_back(v), G[v].emplace_back(u);
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (VIS[i]) continue;
    ans++;
    dfs(i);
  }

  cout << ans << endl;
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
 * AC
 * graphs
 * dfs/bfs
 * connect components
 * https://atcoder.jp/contests/abc126/tasks/abc126_e
 * */
