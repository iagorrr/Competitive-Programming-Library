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

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D",
// "LD", "L"}); int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}; int
// dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int oo = 1'000'000'000;
int T(1);
const int MAX(1000);
int N, M, K, XI, YI, XE, YE;
string G[MAX];
int d[MAX][MAX];

void bfs() {
  queue<pii> q;
  q.emplace(XI, YI);
  d[XI][YI] = 0;

  while (not q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      for (int j = 1; j <= K; j++) {
        int x2 = x + dx[i] * j, y2 = y + dy[i] * j;
        if (x2 < 0 or y2 < 0 or x2 >= N or y2 >= M) break;
        if (G[x2][y2] == '#') break;
        if (d[x2][y2] < d[x][y] + 1) break;

        if (d[x2][y2] == oo) q.emplace(x2, y2);
        d[x2][y2] = min(d[x2][y2], d[x][y] + 1);
      }
    }
  }
}
auto solve() {
  cin >> N >> M >> K;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) d[i][j] = oo;

  for (int i = 0; i < N; i++) cin >> G[i];
  cin >> XI >> YI >> XE >> YE;
  XI--, YI--, XE--, YE--;

  bfs();

  cout << (d[XE][YE] == oo ? -1 : d[XE][YE]) << endl;
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> t;

  for (int i = 1; i <= T; i++) {
    solve();
  }
}

// AC, graphs, dfs/bfs
