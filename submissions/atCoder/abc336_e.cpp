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

const int P10(14);
string K;
ll D;
vi digits;
ll _dp[P10 + 1][9 * P10][9 * P10][2];
ll dp(int pos = 0, int rest = 0, int cursum = 0,
      bool lim = 1) {
  if (pos == len(digits)) return rest == 0 and cursum == D;

  ll &ans = _dp[pos][rest][cursum][lim];

  if (ans != -1) {
    return ans;
  }

  ans = 0;
  int maxi = lim ? digits[pos] : 9;
  for (int i = 0; i <= maxi; i++) {
    ans += dp(pos + 1, (rest * 10 + i) % D, cursum + i,
              lim & (i == maxi));
  }

  return ans;
}

ll solve(const string &k) {
  digits.clear();
  for (auto c : k) digits.emplace_back(c - '0');

  ll ans = 0;
  for (int i = 1; i <= P10 * 9; i++) {
    memset(_dp, -1, sizeof _dp);
    D = i;
    ans += dp();
  }

  return ans;
}

auto run() {
  string x;
  cin >> x;
  cout << solve(x) << '\n';
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
