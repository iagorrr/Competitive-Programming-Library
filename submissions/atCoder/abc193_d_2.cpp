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
string s, t;
ll ha[10], hb[10], h[10];
ld ans;
ll pta, ptb;
ll pt10[] = {1, 10, 100, 1000, 10000, 100000};

auto solve() {
  cin >> k >> s >> t;

  for (int i = 0; i < 4; i++) {
    ha[s[i] - '0']++, hb[t[i] - '0']++, h[s[i] - '0']++,
      h[t[i] - '0']++;
  }

  for (ll i = 1; i <= 9; i++) {
    pta += i * pt10[ha[i]];
    ptb += i * pt10[hb[i]];
  }

  ll win = 0;
  for (ll a = 1; a <= 9; a++) {
    for (ll b = 1; b <= 9; b++) {
      ll preva = a * pt10[ha[a]];
      ll prevb = b * pt10[hb[b]];
      pta += -preva + (a * pt10[ha[a] + 1]);
      ptb += -prevb + (b * pt10[hb[b] + 1]);
      h[a]++, h[b]++;

      ll v = h[a] <= k and h[b] <= k and pta > ptb;

      h[a]--, h[b]--;
      pta -= -preva + (a * pt10[ha[a] + 1]);
      ptb -= -prevb + (b * pt10[hb[b] + 1]);

      win += (k - h[a]) * (k - h[b] - (a == b)) * v;
    }
  }

  ll n = (9ll * k - 8ll) * (9ll * k - 9ll);
  cout << fixed << setprecision(20) << (ld)win / (ld)n
       << endl;
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
