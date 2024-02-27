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

ll findClosestValue(vll& vec, int x) {
  ll closest = vec[0];

  for (int l = 0, r = len(vec) - 1; l <= r;) {
    int mid = l + (r - l) / 2;
    if (vec[mid] == x) {
      return vec[mid];
    }
    if (abs(vec[mid] - x) < abs(closest - x)) {
      closest = vec[mid];
    }
    if (vec[mid] < x) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return closest;
}

auto run() {
  int N, M;
  cin >> N >> M;

  vll XS(N);
  for (auto& xi : XS) cin >> xi;
  sort(all(XS));

  vll WS(M);
  for (auto& wi : WS) cin >> wi;
  sort(all(WS));

  vll diffs;
  ll diffSum = 0;

  for (int i = 1; i + 1 < N; i += 2) {
    ll diff = abs(XS[i] - XS[i + 1]);
    diffSum += diff;
    diffs.eb(diff);
  }
  reverse(all(diffs));

  ll ans = OO;
  for (int i = 0; i < N; i++) {
    auto x = XS[i];
    ll v = findClosestValue(WS, x);
    ll minDiff = abs(x - v);
    dbg(x, minDiff);

    if (i & 1) {
      diffSum -= diffs.back();
      diffs.pop_back();
      diffSum += abs(XS[i - 1] - XS[i + 1]);
    }

    ans = min(ans, diffSum + minDiff);

    if (i & 1) {
      diffSum -= abs(XS[i - 1] - XS[i + 1]);
      diffSum += abs(XS[i] - XS[i - 1]);
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

// AC, greddy, binary search
