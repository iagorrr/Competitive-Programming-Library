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

const int MAXN(1000), MAXQ(2000);
int N1, N2, M1, M2, Q;
vi2d G1(MAXN), G2(MAXN);

int _dp[2][MAXN][MAXQ];
int dp(int i, int u, int k) {
  if (k == 0) {
    return u == 0;
  }

  if (_dp[i][u][k] != -1) return _dp[i][u][k];

  _dp[i][u][k] = 0;
  if (i) {
    for (auto v : G2[u]) {
      _dp[i][u][k] |= dp(i, v, k - 1);
    }
  } else {
    for (auto v : G1[u]) {
      _dp[i][u][k] |= dp(i, v, k - 1);
    }
  }

  return _dp[i][u][k];
}
auto solve() {
  memset(_dp, -1, sizeof _dp);
  cin >> N1 >> N2 >> M1 >> M2;

  while (M1--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G1[v].emplace_back(u);
  }

  while (M2--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G2[v].emplace_back(u);
  }

  cin >> Q;
  while (Q--) {
    int qi;
    cin >> qi;

    bool ans = false;
    for (int i = 0; i <= qi and !ans; i++) {
      int j = qi - i;
      ans |= (dp(0, N1 - 1, i) and dp(1, N2 - 1, j));
    }
    cout << (ans ? "Yes\n" : "No\n");
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

// AC, graphs, dfs/bfs, dag, dynamic programming
/*
 * AC
 * graphs
 * bfs/dfs
 * dag
 * dynamic programming
 * */
