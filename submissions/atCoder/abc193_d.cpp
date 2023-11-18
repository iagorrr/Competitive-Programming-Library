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

ll k;
string _s, _t;
vll s, t;
ll pt10[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
ld ans;
vector<int> ha(10), hb(10), h(10);
bool win(ll a, ll b) {
  ll pta, ptb;
  pta = ptb = 0;

  for (ll i = 1; i <= 9; i++) {
    pta += i * pt10[ha[i] + (i == a)];
    ptb += i * pt10[hb[i] + (i == b)];
  }

  return pta > ptb;
}

ld prob(ll a, ll b) {
  ll denom = 9 * k - 4 - 4;
  ll num1 = k - h[a];
  ll num2 = k - h[b] - (a == b);
  return (ld)num1 / (ld)denom * (ld)num2 / (ld)(denom - 1);
}

auto solve() {
  cin >> k >> _s >> _t;

  for (int i = 0; i < 4; i++) {
    t.emplace_back(_t[i] - '0'),
      s.emplace_back(_s[i] - '0');
  }

  for (int i = 0; i < 4; i++) {
    ha[s[i]]++, hb[t[i]]++, h[s[i]]++, h[t[i]]++;
  }

  t.emplace_back(0), s.emplace_back(0);

  for (ll a = 1; a <= 9; a++) {
    for (ll b = 1; b <= 9; b++) {
      h[a]++, h[b]++;
      bool v = h[a] <= k and h[b] <= k and win(a, b);
      h[a]--, h[b]--;

      if (!v) continue;

      ans += prob(a, b);
    }
  }

  cout << fixed << setprecision(20) << ans << endl;
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

// AC, math, probability
