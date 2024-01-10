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
const int MAXN(1'000'000);

vi pos1;
vll2d _dp;
vll xs;

ll dp(int p, int d) {
  if (p < 0 or p >= len(pos1)) return 0;
  if (_dp[d][p] != -1) return _dp[d][p];

  if (d) {  // right
    _dp[d][p] = max(dp(p - 1, 0), dp(p - 1, 1)) +
                max(0ll, xs[pos1[p] + 1]);
  } else {  // left 
    _dp[d][p] = dp(p - 1, 0) + max(0ll, xs[pos1[p] - 1]);
  }

  return _dp[d][p];
}

auto run() {
  string s;
  cin >> s;

  int k = 0;
  xs.clear();
  xs.emplace_back(0);
  for (auto c : s) {
    if (c == 'A')
      k++;
    else {
      xs.emplace_back(k);
      xs.emplace_back(-1);
      k = 0;
    }
  }
  if (k) xs.emplace_back(k);
  xs.emplace_back(0);

  pos1.clear();
  for (int i = 0; i < len(xs); i++) {
    if (xs[i] == -1) pos1.emplace_back(i);
  }

  _dp = vll2d(2, vll(len(pos1), -1));
  ll ans = 0;

  for (int i = 0; i < len(pos1); i++) {
    ans = max(dp(i, 0), dp(i, 1));
  }
  cout << ans << '\n';
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  cin >> T;

  for (int i = 1; i <= T; i++) {
    run();
  }
}

/*
 * AC
 * Strings
 * Dynamic Programming
 * https://codeforces.com/problemset/problem/1873/G
 * */
