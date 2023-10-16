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
int R, C;
bool ans(false);
string S;
vector<string> grid;

bool check(int x, int y) {
  for (int i = 0; i < C; i++) {
    if (S[i] == '1' and grid[x][(i + y) % C] == '1') return false;
  }
  return true;
}

bool vis[1001][101];
void bfs() {
  memset(vis, 0, sizeof(vis));
  vector<pii> stck;
  for (int i = 0; i <= C; i++)
    if (check(0, i)) {
      stck.emplace_back(0, i);
      vis[0][i] = true;
    }

  while (not stck.empty()) {
    auto [x, y] = stck.back();
    vis[x][y] = true;
    stck.pop_back();
    if (x == R - 1) {
      ans = true;
      return;
    }

    for (int i = 0; i < 4; i++) {
      int x2 = (x + dx[i]);
      int y2 = (((y + dy[i]) % C) + C) % C;
      if (x2 < 0 or x2 > R or vis[x2][y2] or not check(x2, y2)) continue;
      vis[x2][y2] = true;
      stck.emplace_back(x2, y2);
    }
  }
}
auto solve() {
  cin >> R >> C;
  cin >> S;

  S = S + S;

  for (int i = 0; i < R; i++) {
    string tmp;
    cin >> tmp;
    grid.emplace_back(tmp);
  }

  bfs();
  reverse(all(S));
  bfs();

  cout << (ans ? "Y" : "N") << endl;
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

// AC, grahs, dfs/bfs
