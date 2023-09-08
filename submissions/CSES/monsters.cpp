#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int)__x.size()
using ll = long long;
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
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

const int oo = 1e9;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
vc dir({'L', 'R', 'U', 'D'});
vi2d getMonstersDist(vector<string> &grid, int n, int m) {
  vi2d dists(n, vi(m, oo));
  priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>>
    pq;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'M') {
        dists[i][j] = 0;
        pq.push({0, i, j});
      }
    }
  }

  while (not pq.empty()) {
    auto [d, x, y] = pq.top();
    pq.pop();
    for (int i = 0; i < 4; i++) {
      int x2 = x + dx[i];
      int y2 = y + dy[i];
      if (x2 >= 0 and y2 >= 0 and x2 < n and y2 < m and grid[x2][y2] != '#' and
          dists[x2][y2] > d + 1) {
        dists[x2][y2] = d + 1;
        pq.push({d + 1, x2, y2});
      }
    }
  }
  return dists;
}
void run() {
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);

  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }

  vi2d monstersDist = getMonstersDist(grid, n, m);
  int sx = -1, sy = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'A') {
        sx = i, sy = j;
      }
    }
  }
  if (sx == 0 or sx == n-1 or sy == 0 or sy == m-1) {
    cout << "YES\n";
    cout << 0 << endl;
    return;
  }
  priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>>
    pq;

  vector<vector<array<int, 3>>> par(n, vector<array<int, 3>>(m, {-1, -1, -1}));
  vi2d dists(n, vi(m, oo));
  pq.push({0, sx, sy});
  dists[sx][sy] = 0;
  int fx = -1, fy = -1;
  while (not pq.empty()) {
    auto [d, x, y] = pq.top();
    pq.pop();

    for (int i = 0; i < 4; i++) {
      int x2 = x + dx[i];
      int y2 = y + dy[i];
      if (x2 >= 0 and y2 >= 0 and x2 < n and y2 < m and grid[x2][y2] != '#' and
          monstersDist[x2][y2] > d + 1 and dists[x2][y2] > d + 1) {
        pq.push({d + 1, x2, y2});
        par[x2][y2] = {x, y, dir[i]};
        dists[x2][y2] = d + 1;
        if (x2 == n - 1 or y2 == m - 1 or x2 == 0 or y2 == 0) {
          fx = x2, fy = y2;
          break;
        }
      }
    }

    if (fx != -1) break;
  }

  if (fx == -1) {
    cout << "NO\n";
  } else {
    int cx = fx, cy = fy;
    char cur = (char)par[cx][cy][2];
    string path;
    while (cur != -1) {
      path += (char)cur;
      int tx = cx;
      cx = par[cx][cy][0];
      int ty = cy;
      cy = par[tx][cy][1];
      cur = (char)par[cx][cy][2];
    }
    reverse(all(path));
    cout << "YES\n";
    cout << len(path) << endl;
    cout << path << endl;
  }
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, graph, shortest path, grid
