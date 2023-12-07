#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...) 42
#endif
#define endl '\n'
#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
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
int lg2(ll x) { return __builtin_clzll(1) - __builtin_clzll(x); }

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D",
// "LD", "L"}); int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}; int
// dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll oo = 1e18;
int T(1);

const int maxn(1'000'000);
const ll mod = 1'000'000'000 + 7;
ll pow8[maxn + 1];
ll pow2[maxn + 1];

vll fats(maxn + 1);

void precompute() {
  pow8[0] = 1, pow2[0] = 1;

  for (ll i = 1; i <= maxn; i++) {
    pow8[i] = (pow8[i - 1] * 8ll) % mod;
    pow2[i] = (pow2[i - 1] * 2ll) % mod;
  }

  fats[0] = 1;
  for (ll i = 1; i <= maxn; i++) {
    fats[i] = (fats[i - 1] * i) % mod;
  }
}
ll fpow(ll a, ll n) {
  if (n == 0ll)
    return 1ll;
  if (n == 1ll)
    return a;
  ll x = fpow(a, n / 2ll) % mod;
  return ((x * x) % mod * (n & 1ll ? a : 1ll)) % mod;
}

ll binommod(ll n, ll k) {
  ll upper = fats[n];
  ll lower = (fats[k] * fats[n - k]) % mod;
  return (upper * fpow(lower, mod - 2ll)) % mod;
}

auto solve() {
  precompute();
  ll n;
  cin >> n;
  if (n == 2) {
    cout << 2 << endl;
    return;
  }

  if (n == 1) {
    cout << 0 << endl;
    return;
  }

  ll ans = 0;
  for (ll i = 2; i <= n; i++) {
    ll prod = 0;
    prod = ((pow2[i] - 2ll) + mod) % mod;
    prod = (prod * pow8[n - i]) % mod;
    prod = (prod * binommod(n, i)) % mod;
    ans = (ans + prod) % mod;
  }
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
 * Combinatorics
 * https://atcoder.jp/contests/abc178/tasks/abc178_c
 * */
