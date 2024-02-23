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

const int oo = 1e9;
const ll OO = 1e18;

int T(1);

const int MAXD(500);
int H, W;
int G[MAXD + 1][MAXD + 1];

auto run() {
  cin >> H >> W;

  for (int i = 1; i <= H; i++)
    for (int j = 1; j <= W; j++) cin >> G[i][j];

  int x = 1, y = 1;
  int mvs = 0;
  int dy = 1, dx;
  vector<array<int, 4>> ans;
  while (mvs < H * W - 1) {
    int nx = x, ny = y;
    if (y + dy < 1 or y + dy > W) {
      nx += 1;
      dy = -dy;
    } else {
      ny += dy;
    }

    if (G[x][y] & 1) {
      G[x][y]--;
      G[nx][ny]++;
      ans.push_back({x, y, nx, ny});
    }

    mvs++;
    x = nx, y = ny;
  }

  cout << len(ans) << '\n';
  for (auto [a, b, c, d] : ans) {
    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
  }
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

// AC, greddy
