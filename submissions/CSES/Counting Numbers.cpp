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

vi digits;
ll DP[18 + 1][10][2][2];
ll call(int pos = 0, int prev = 0, bool lim = true,
        bool only0 = true) {
  if (pos == len(digits)) return 1;

  ll &ans = DP[pos][prev][lim][only0];

  if (ans != -1) {
    return DP[pos][prev][lim][only0];
  }

  ans = 0;
  int maxi = lim ? digits[pos] : 9;
  for (int i = 0; i <= maxi; i++) {
    if (i == prev and !(!prev and !i and only0)) continue;
    ans +=
      call(pos + 1, i, lim and i == maxi, only0 & (i == 0));
  }

  return ans;
}

ll solve(ll x) {
  memset(DP, -1, sizeof DP);
  digits.clear();
  while (x) digits.emplace_back(x % 10), x /= 10;
  reverse(all(digits));
  return call();
}

auto run() {
  ll a, b;
  cin >> a >> b;
  a = solve(a - 1), b = solve(b);
  cout << b - a << '\n';
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> T;

  for (int i = 1; i <= T; i++) {
    run();
  }
}

// AC, digit dp
