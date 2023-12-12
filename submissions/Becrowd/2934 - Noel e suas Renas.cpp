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

const int oo = 1e9;
int T(1);

const int MAXN(1'00'000), MAXX(1'000'000);
int N;
int XS[MAXN + 1];
int dp[MAXX + 1][2];

auto solve() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> XS[i];
  }

  auto first = XS[1];
  dp[0][1] = dp[0][0] = -oo;
  dp[first][0] = 1;
  if (first > 1) dp[first - 1][1] = 1;
  dp[first + 1][1] = 2;

  for (int i = 2; i <= N; i++) {
    auto cur = XS[i];

    dp[cur][0] = max(dp[cur][0], 1);
    dp[cur][0] = max(dp[cur][0], dp[cur - 1][0] + 1);

    dp[cur][1] = max(dp[cur][1], dp[cur - 1][1] + 1);
    if (cur > 1)
      dp[cur][1] = max(dp[cur][1], dp[cur - 2][0] + 2);
  }

  int ans = -oo;
  for (int i = 0; i <= MAXX; i++)
    ans = max({ans, dp[i][0], dp[i][1]});
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
 * DP
 * */
