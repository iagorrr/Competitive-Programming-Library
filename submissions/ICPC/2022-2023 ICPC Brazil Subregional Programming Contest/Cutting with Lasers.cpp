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

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D", "LD", "L"});
// int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
// int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll oo = 1e18;
int N;
const int TMAX(1000 * 3);
vi2d grid(TMAX + 1, vi(TMAX + 1));
int ans, cnt;
int id = 1;
void dfs(int li, int ci) {
  vector<pii> stck;
  stck.emplace_back(li, ci);
  grid[li][ci] = id;

  while (not stck.empty()) {
    auto [l, c] = stck.back();
    stck.pop_back();

    cnt++;
    ans = max(ans, cnt);

    for (int i = 0; i < 4; i++) {
      int l2 = l + dx[i];
      int c2 = c + dy[i];

      if (grid[l2][c2] == -1) continue;  // wall

      l2 = l + dx[i] * 2;
      c2 = c + dy[i] * 2;

      if (grid[l2][c2] != 0) continue;  // already visited
      stck.emplace_back(l2, c2);
      grid[l2][c2] = id;
    }
  }
}
vector<pii> pts;
void setwalls() {
  for (int i = 0; i <= TMAX; i++) {
    grid[0][i] = -1;
    grid[TMAX][i] = -1;
    grid[i][0] = -1;
    grid[i][TMAX] = -1;
  }

  for (int i = 1; i <= N; i++) {
    auto [xp, yp] = pts[i - 1];
    auto [xc, yc] = pts[i];
    int dx2 = xc - xp ? (xc - xp) / abs(xc - xp) : 0;
    int dy2 = yc - yp ? (yc - yp) / abs(yc - yp) : 0;

    int l, c, fl, fc;
    l = xp * 2;
    c = yp * 2;
    fl = xc * 2;
    fc = yc * 2;

    while (c != fc or l != fl) {
      grid[l][c] = -1;
      l += dx2;
      c += dy2;
    }
  }
}

auto solve() {
  cin >> N;

  for (int i = 0; i <= N; i++) {
    int x, y;
    cin >> x >> y;
    pts.emplace_back(y, x);
  }

  setwalls();

  id = 1;
  dfs(TMAX - 1, TMAX - 1);
  ans = 0;

  for (int l = 1; l < TMAX; l += 2) {
    for (int c = 1; c < TMAX; c += 2) {
      if (grid[l][c] == 0) {
        cnt = 0;
        id++;
        dfs(l, c);
      }
    }
  }

  cout << ans << endl;
}
int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif
  int t;
  t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}

// AC, graphs, dfs
