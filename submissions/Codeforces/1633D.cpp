#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define endl '\n'
#define fastio                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
// #define int long long
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
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define rep(i, begin, end)                              \
  for (__typeof(begin) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end));                  \
       i += 1 - 2 * ((begin) > (end)))

int lg2(ll x) {
  return __builtin_clzll(1) - __builtin_clzll(x);
}

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D",
// "LD", "L"}); int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}; int
// dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll OO = 1e18;
const int oo = 1e9;

int T(1);

pair<ll, vi> knapsack(const vll &points, const vi &costs,
                      int maxCost) {
  int n = len(points) - 1;  // ELEMENTS START AT INDEX 1 !
  vll2d dp(n + 1, vll(maxCost + 1));
  vector<vector<char>> ps(n + 1, vector<char>(maxCost + 1));

  for (int m = 0; m <= maxCost; ++m) dp[0][m] = 0;

  for (int i = 1; i <= n; ++i) {
    dp[i][0] = dp[i - 1][0] + (costs[i] == 0) * points[i];
    ps[i][0] = costs[i] == 0;
  }

  for (int i = 1; i <= n; ++i) {
    for (int m = 1; m <= maxCost; ++m) {
      dp[i][m] = dp[i - 1][m];
      ps[i][m] = 0;
      int w = costs[i];
      ll v = points[i];

      if (w <= m and dp[i - 1][m - w] + v > dp[i][m]) {
        dp[i][m] = dp[i - 1][m - w] + v;
        ps[i][m] = 1;
      }
    }
  }

  vi is;
  for (int i = n, m = maxCost; i >= 1; --i) {
    if (ps[i][m]) {
      is.emplace_back(i - 1);
      m -= costs[i];
    }
  }

  return {dp[n][maxCost], is};
}

vi cost(2'000 + 1, oo);
int worst = 0;
auto run() {
  int N, K;
  cin >> N >> K;

  vll BS(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> BS[i];
  }

  vll CS(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> CS[i];
  }

  vi WS(N + 1);
  for (int i = 1; i <= N; i++) {
    WS[i] = cost[BS[i]];
  }

  ll ans = knapsack(CS, WS, min(K, worst * N)).first;
  cout << ans << '\n';
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  cost[1] = 0;
  for (int i = 1; i <= 1'000; i++) {
    for (int j = 1; j <= i; j++) {
      cost[i + i / j] = min(cost[i + i / j], cost[i] + 1);
      worst = max(worst, cost[i + i / j]);
    }
  }

  cin >> T;

  for (int t = 1; t <= T; t++) {
    run();
  }
}

// AC, dp, knapsack
