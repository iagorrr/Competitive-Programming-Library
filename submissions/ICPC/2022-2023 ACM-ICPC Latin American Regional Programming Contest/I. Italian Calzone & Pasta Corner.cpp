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

vector<pii> dirs({{-1, 0}, {0, 1}, {1, 0}, {0, -1}});

const ll oo = 1e18;

const int maxr(100), maxc(100);
int grid[maxr][maxc];
pii pos[maxr * maxc + 1];
int r, c;
int ans(0);

bool vis1[maxr * maxc + 1];
bool vis2[maxr * maxc + 1];
void bfs(int k) {
  memset(vis2, 0, sizeof(vis2));
  priority_queue<int, vi, greater<int>> pq;
  pq.emplace(k);
  int curans = 0;
  int mk = 0;
  while (not pq.empty()) {
    auto cur = pq.top();
    pq.pop();

    if (cur < mk) continue;
    mk = cur;
    curans++;

    auto [x, y] = pos[cur];

    for (auto [dx, dy] : dirs) {
      int x2 = x + dx, y2 = y + dy;
      if (x2 < 0 or y2 < 0 or x2 >= r or y2 >= c) continue;
      auto cur2 = grid[x2][y2];
      if (cur2 < cur) continue;
      if (vis2[cur2]) continue;
      vis2[cur2] = 1;
      vis1[cur2] = 1;
      pq.emplace(cur2);
    }
  }
  ans = max(ans, curans);
}

auto solve() {
  memset(vis2, 0, sizeof(vis2));
  cin >> r >> c;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> grid[i][j];
      pos[grid[i][j]] = {i, j};
    }
  }

  for (int i = 1; i <= r * c; i++) {
    if (vis1[i]) continue;
    bfs(i);
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

// AC, graphs, bfs/dfs
