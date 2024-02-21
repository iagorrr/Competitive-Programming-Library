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

const int oo = 1'000'000'000;
int T(1);
const int MAXD(1'000);

int H, W, ii, ij, fi, fj;
vi2d ds(MAXD, vi(MAXD, oo));
vector<string> GRID;

bool valid(int i, int j) {
  return !(i < 0 or j < 0 or i >= H or j >= W or
           GRID[i][j] == '#');
}

void bfs01() {
  ds[ii][ij] = 0;
  deque<pii> dq;
  dq.emplace_front(ii, ij);

  while (len(dq)) {
    auto [ui, uj] = dq.front();
    int du = ds[ui][uj];
    dbg(du, ui, uj);
    dq.pop_front();

    for (int i = 0; i < 4; i++) {
      int ui2 = ui + dx[i], uj2 = uj + dy[i];
      if (!valid(ui2, uj2)) continue;
      if (ds[ui2][uj2] <= du) continue;
      ds[ui2][uj2] = du;
      dq.emplace_front(ui2, uj2);
    }

    for (int i = ui - 2; i <= ui + 2; i++) {
      for (int j = uj - 2; j <= uj + 2; j++) {
        if (!valid(i, j)) continue;
        if (ds[i][j] <= du + 1) continue;
        ds[i][j] = du + 1;
        dq.emplace_back(i, j);
      }
    }
  }
}

auto run() {
  cin >> H >> W;
  cin >> ii >> ij;
  cin >> fi >> fj;

  ii--, ij--, fi--, fj--;

  GRID.resize(H);
  for (auto &x : GRID) cin >> x;

  bfs01();

  cout << (ds[fi][fj] == oo ? -1 : ds[fi][fj]) << '\n';
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

// AC, bfs 01
