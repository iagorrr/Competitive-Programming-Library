#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(x) (int)x.size()
#define all(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;

vector<pair<int, int>> dir4{{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

vector<vector<ll>> bfs(const vector<string> &g) {
  queue<pair<int, int>> q;
  for (int i = 0; i < len(g); i++)
    for (int j = 0; j < len(g[0]); j++)
      if (g[i][j] == 'E') q.emplace(i, j);

  vector<vector<ll>> dist(g.size(), vector<ll>(g[0].size(), INT_MAX));
  dist[q.front().first][q.front().second] = 0;

  while (not q.empty()) {
    auto cur = q.front();
    q.pop();

    for (auto [dx, dy] : dir4) {
      auto x = cur.first + dx;
      auto y = cur.second + dy;

      if (x >= 0 and y >= 0 and x < len(g) and y < len(g[0])) {
        auto d = dist[cur.first][cur.second] + 1;
        if (dist[x][y] > d and g[x][y] == '.') {
          q.emplace(x, y);
          dist[x][y] = d;
        }
      }
    }
  }

  return dist;
}

void run() {
  int n, m;
  cin >> n >> m;
  vector<string> g(n);
  for (auto &x : g) cin >> x;

  auto dist = bfs(g);
  int q;
  cin >> q;

#define DIST(_x, _y) \
  (_x < 0 or _y < 0 or _x >= len(g) or _y >= len(g[0]) ? INT_MAX : dist[_x][_y])
  while (q--) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    if (g[x][y] == '#')
      cout << "W\n";
    else if (g[x][y] == 'E')
      cout << "E\n";
    else if (g[x][y] == 'X')
      cout << "X\n";
    else if (dist[x][y] == INT_MAX)
      cout << "?\n";
    else {
      int d = 0;
      string dirname = "LDRU";
      for (int i = 1; i < 4; i++) {
        int x2 = x + dir4[i].first;
        int y2 = y + dir4[i].second;

        int x3 = x + dir4[d].first;
        int y3 = y + dir4[d].second;
        if (DIST(x2, y2) < DIST(x3, y3)) d = i;
      }

      cout << dirname[d] << '\n';
    }
  }
}

int32_t main() {
  fastio;
  int t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, graph, bfs
