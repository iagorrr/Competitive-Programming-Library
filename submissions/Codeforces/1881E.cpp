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
const int maxn(2 * 1'00'000);
int n;
int dp[maxn];
ll xs[maxn];

int dfs(int u = 0) {
  // no movement necessary anymore
  if (u == n) return 0;

  // already computed
  if (dp[u] != n) return dp[u];

  // answer considering removing u
  dp[u] = min(dp[u], dfs(u + 1) + 1);

  // if can take u than take and only consider begin of the
  // next block
  if (u + xs[u] < n) dp[u] = min(dp[u], dfs(u + xs[u] + 1));

  return dp[u];
}
auto solve() {
  cin >> n;

  for (int i = 0; i < n; i++) cin >> xs[i], dp[i] = n;

  cout << dfs() << endl;
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  cin >> T;

  for (int i = 1; i <= T; i++) {
    solve();
  }
}

// AC, dp, dynamic programming
