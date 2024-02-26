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

const ll OO = 1e18;
const int oo = 1e9;

int T(1);

bool check(int k, vi xs, const vi &maxd) {
  for (int i = len(xs) - 1; i >= 2; i--) {
    if (xs[i] < k) return false;

    ll diff = xs[i] - k;
    ll thisd = diff / 3ll;

    ll trued = min(maxd[i], thisd);

    xs[i] -= trued * 3;
    xs[i - 1] += trued;
    xs[i - 2] += 2 * trued;
  }

  for (auto &xi : xs) {
    if (xi < k) return false;
  }

  return true;
}

auto run() {
  int n;
  cin >> n;

  vi xs(n), maxd(n);
  for (auto &xi : xs) {
    cin >> xi;
  }

  for (int i = 0; i < n; i++) {
    maxd[i] = xs[i] / 3;
  }

  int l = 1, r = 2 * 1e9;
  int ans = 1;
  while (l <= r) {
    int mid = midpoint(l, r);

    if (check(mid, xs, maxd)) {
      ans = max(mid, ans);
      l = mid + 1;
    } else {
      r = mid - 1;
    }
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

// AC, greddy, binary search
