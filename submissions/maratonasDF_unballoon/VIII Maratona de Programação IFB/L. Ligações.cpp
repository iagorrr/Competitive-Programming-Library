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

/*
 * dp(i,j) = ways to reach time `i` with `j` hours done
 * */

ll n, m;
const int MAXM(25 * 100 + 25 + 1);
vll2d dp(MAXM + 50, vll(MAXM + 50));
vll2d xs(MAXM);

auto solve() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    ll start, takes;
    cin >> start >> takes;
    xs[start].emplace_back(takes);
  }

  dp[0][0] = 1;

  for (ll i = 0; i < MAXM; i++) {
    // because we cant update in range, this for is like
    // prefix sum
    for (ll j = 0; j < MAXM; j++) dp[i + 1][j] += dp[i][j];

    // considering you works dj starting at i
    for (auto dj : xs[i]) {
      for (ll j = 0; j < MAXM; j++) {
        dp[i + dj][j + dj] += dp[i][j];
      }
    }
  }

  cout << dp[MAXM][m] << endl;
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

// AC, dynamic programming
