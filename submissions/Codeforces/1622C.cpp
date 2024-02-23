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
int T(1);

auto run() {
  ll N, K;
  cin >> N >> K;

  vll XS2(N);
  ll totSum = 0;
  for (auto &xi : XS2) {
    cin >> xi;
    totSum += xi;
  }

  vector<__int128_t> XS(all(XS2));

  ll ans = totSum;
  sort(all(XS));
  reverse(XS.begin() + 1, XS.end());
  for (__int128_t i = 0; i <= N - 1; i++) {
    totSum -= XS[i];
    __int128_t minDecre = OO;

    __int128_t l = 0, r = OO;
    while (l <= r) {
      auto mid = (r-l)/2 + l;
      if ((i + 1ll) * (XS[0] - mid) + totSum <= K) {
        minDecre = min(minDecre, mid);
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    ans = min(ans, (ll)minDecre + (ll)i);
  }

  cout << ans << '\n';
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  cin >> T;

  for (int t = 1; t <= T; t++) {
    run();
  }
}

// AC, binary search, brute force, greddy, sortings
