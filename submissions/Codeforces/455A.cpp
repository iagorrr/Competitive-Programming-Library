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
const int MAXN(1'00'000);

map<ll, ll> hs;

ll _dp[MAXN + 1][2];
ll dp(ll x, bool k) {
  if (x <= 0) return 0ll;
  if (_dp[x][k] != -1) return _dp[x][k];
  if (k)
    return _dp[x][k] =
             hs[x] * x + max(dp(x - 2, 0), dp(x - 2, 1));
  return _dp[x][k] = max(dp(x - 1, 0), dp(x - 1, 1));
}

auto run() {
  int n;
  cin >> n;

  ll xm = -oo;
  for (int i = 0; i < n; i++) {
    ll xi;
    cin >> xi;

    hs[xi]++, xm = max(xm, xi);
  }

  cout << max(dp(xm, 0), dp(xm, 1)) << '\n';
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif
  memset(_dp, -1, sizeof _dp);

  // cin >> T;

  for (int i = 1; i <= T; i++) {
    run();
  }
}

/*
 * AC
 * Dynamic Programming
 * DP
 * https://codeforces.com/problemset/problem/455/A
 * */
