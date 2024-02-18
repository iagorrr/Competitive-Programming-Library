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

const ll oo = 1e18;
int T(1);

const ll MOD = 1e9 + 7;
const ll MAXN = 1'00'000;
ll FACT[MAXN + 1];
void precompute() {
  #warning Remember to call precompute before use binommod !
  FACT[0] = 1;
  for (ll i = 1; i <= MAXN; i++) {
    FACT[i] = (FACT[i - 1] * i) % MOD;
  }
}

ll fpow(ll a, ll k) {
  ll ret = 1;
  while (k) {
    if (k & 1) ret = (ret * a) % MOD;
    a = (a * a) % MOD;
    k >>= 1;
  }
  return ret;
}

ll binommod(ll n, ll k) {
  ll upper = FACT[n];
  ll lower = (FACT[k] * FACT[n - k]) % MOD;
  return (upper * fpow(lower, MOD - 2ll)) % MOD;
}

auto run() {
  ll N;
  cin >> N;

  ll aux = 0;
  for (int i = 1; i < N; i++) {
    ll sum = i, boxes = N - 1;

    ll fi = (binommod(sum + boxes - 1, sum)) % MOD;

    dbg(fi, fi * (N - i));
    aux = (aux + fi * (N - i)) % MOD;
  }

  dbg(aux);
  cout << (N + aux * 2) % MOD << '\n';
}
int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif
  precompute();

  // cin >> T;

  for (int t = 1; t <= T; t++) {
    run();
  }
}

// AC, combinatorics
