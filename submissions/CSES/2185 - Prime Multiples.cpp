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
#define int long long
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

auto run() {
  ll n, k;
  cin >> n >> k;

  vll primes(k);
  for (auto &pi : primes) cin >> pi;

  ll ans = 0;
  __int128 n2 = n;
  for (ll mask = 1; mask < (1ll << k); mask++) {
    __int128 prod = 1;

    ll bits = 0;
    bool greater = 0;
    for (ll i = 0; (1ll << i) <= mask; i++) {
      if (mask & (1ll << i)) {
        bits++;
        if (prod * primes[i] > n2) {
          greater = 1;
          break;
        }
        prod *= primes[i];
      }
    }

    if (greater) continue;

    ll cur = n / prod;
    if (bits & 1) {
      ans += cur;
    } else {
      ans -= cur;
    }
  }

  cout << ans << '\n';
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> T;

  for (int t = 1; t <= T; t++) {
    run();
  }
}

// AC, inclusion exclusion
