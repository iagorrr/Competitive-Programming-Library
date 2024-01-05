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

const ll MOD = 1000027957;
const ll MOD2 = 1000015187;
const ll P = 31;

ll p[MAXN + 1], p2[MAXN + 1];
void precompute() {
  p[0] = p2[0] = 1;
  for (int i = 1; i <= MAXN; i++)
    p[i] = (P * p[i - 1]) % MOD,
    p2[i] = (P * p2[i - 1]) % MOD2;
}

struct Hash {
  int n;
  vll h, h2, hi, hi2;
  Hash() {}
  Hash(const string &s)
    : n(len(s)), h(n), h2(n), hi(n), hi2(n) {
    h[0] = h2[0] = s[0];
    for (int i = 1; i < n; i++)
      h[i] = (s[i] + h[i - 1] * P) % MOD,
      h2[i] = (s[i] + h2[i - 1] * P) % MOD2;

    hi[n - 1] = hi2[n - 1] = s[n - 1];
    for (int i = n - 2; i >= 0; i--)
      hi[i] = (s[i] + hi[i + 1] * P) % MOD,
      hi2[i] = (s[i] + hi2[i + 1] * P) % MOD2;
  }
  pll query(int l, int r) {
    ll hash =
      (h[r] - (l ? h[l - 1] * p[r - l + 1] % MOD : 0));
    ll hash2 =
      (h2[r] - (l ? h2[l - 1] * p2[r - l + 1] % MOD2 : 0));

    return {(hash < 0 ? hash + MOD : hash),
            (hash2 < 0 ? hash2 + MOD2 : hash2)};
  }
  pll query_inv(int l, int r) {
    ll hash =
      (hi[l] -
       (r + 1 < n ? hi[r + 1] * p[r - l + 1] % MOD : 0));
    ll hash2 =
      (hi2[l] -
       (r + 1 < n ? hi2[r + 1] * p2[r - l + 1] % MOD2 : 0));
    return {(hash < 0 ? hash + MOD : hash),
            (hash2 < 0 ? hash2 + MOD2 : hash2)};
  }
};

auto run() {
  string s;
  cin >> s;
  int n = len(s);
  int l = 0, r = n - 1;
  while (l < r and s[l] == s[r]) {
    l++, r--;
  }
  if (l >= r) {
    cout << s << '\n';
    return;
  }

  Hash hs(s);
  int szl = 0;
  for (int i = 0; i + l <= r; i++) {
    if (hs.query(l, l + i) == hs.query_inv(l, l + i))
      szl = i;
  }

  int szr = 0;
  for (int i = 0; r - i >= l; i++) {
    if (hs.query(r - i, r) == hs.query_inv(r - i, r))
      szr = i;
  }

  for (int i = 0; i <= l - 1; i++) cout << s[i];
  if (szl >= szr) {
    for (int i = l; i <= l + szl; i++) cout << s[i];
  } else {
    for (int i = r - szr; i <= r; i++) cout << s[i];
  }
  for (int i = r + 1; i < n; i++) cout << s[i];
  cout << '\n';
}

int32_t main(void) {
  precompute();
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
 * https://codeforces.com/contest/1326/problem/D1
 * strings
 * palindromes
 * hash
 * */
