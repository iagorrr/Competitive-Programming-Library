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

const ll P = 31;
const ll MOD = 1e9 + 9;
const int MAXN(1e6);

ll ppow[MAXN + 1];
void pre_calc() {
  ppow[0] = 1;
  for (int i = 1; i <= MAXN; i++)
    ppow[i] = (ppow[i - 1] * P) % MOD;
}

struct Hash {
  int n;
  vll h, hi;
  Hash(const string &s) : n(s.size()), h(n), hi(n) {
    h[0] = s[0];
    hi[n - 1] = s[n - 1];
    for (int i = 1; i < n; i++) {
      h[i] = (s[i] + h[i - 1] * P) % MOD;
      hi[n - i - 1] =
        (s[n - i - 1] + hi[n - i - 1] * P) % MOD;
    }
  }

  ll qry(int l, int r) {
    ll hash =
      (h[r] - (l ? h[l - 1] * ppow[r - l + 1] % MOD : 0));
    return hash < 0 ? hash + MOD : hash;
  }

  ll qry_inv(int l, int r) {
    ll hash =
      (hi[l] -
       (r + 1 < n ? hi[r + 1] * ppow[r - l + 1] % MOD : 0));
    return hash < 0 ? hash + MOD : hash;
  }
};
auto run() {
  string s;
  cin >> s;

  Hash hs(s);
  int n = len(s);
  for (int sz = 1; sz <= n; sz++) {
    bool ok = 1;
    dbg(sz);
    ll ho = hs.qry(0, sz - 1);
    dbg(ho);

    for (int j = 0; j + sz - 1 < n and ok; j += sz) {
      ll h2 = hs.qry(j, j + sz - 1);
      dbg(h2);
      ok &= ho == h2;
    }

    if (n % sz)
      ok &=
        hs.qry(0, n % sz - 1) ==
        hs.qry((n / sz) * sz, (n / sz) * sz + (n % sz) - 1);

    if (ok) {
      cout << sz << ' ';
    }
  }

  cout << '\n';
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif
  pre_calc();

  // cin >> T;

  for (int t = 1; t <= T; t++) {
    run();
  }
}

// AC, strings, hashing
