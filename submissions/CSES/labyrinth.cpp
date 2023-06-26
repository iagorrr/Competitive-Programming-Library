// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define rep(i, l, r) for (int i = (l); i < (r); i++)
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
using vs = vector<string>;
#define INV(xxxx)                                                              \
  for (auto &xxx : xxxx)                                                       \
    cin >> xxx;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first

void dbg_out() { cerr << endl; }
template <typename H, typename... T> void dbg_out(H h, T... t) {
  cerr << ' ' << h;
  dbg_out(t...);
}
#define dbg(...)                                                               \
  {                                                                            \
    cerr << #__VA_ARGS__ << ':';                                               \
    dbg_out(__VA_ARGS__);                                                      \
  }

vs grid(1000);
int n, m;
pii a, b;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
string dir("DULR");
char vis[1'000][1'000];
int parent[1'000][1'000];

bool check(int x, int y) {
  if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == '#' || vis[x][y])
    return false;

  return true;
}
string reconstruct() {
  int x, y;
  x = b.fst;
  y = b.snd;
  string ans;
  while (make_pair(x, y) != a) {
    int parent_dir = parent[x][y];
    ans.push_back(dir[parent_dir]);
    x += (-dx[parent_dir]);
    y += (-dy[parent_dir]);
  }
  return ans;
}
void run() {
  cin >> n >> m;
  rep(i, 0, n) { cin >> grid[i]; }

  // find a an d b pos
  rep(i, 0, n) {
    rep(j, 0, m) {
      if (grid[i][j] == 'A')
        a = {i, j};
      if (grid[i][j] == 'B')
        b = {i, j};
    }
  }
  string ans;
  queue<pair<pii, int>> q;
  q.emplace(pair<pii, int>(a, 0));
  vis[a.fst][a.snd] = true;
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    if (cur.fst == b) {
      if (ans.size() == 0 || (int)ans.size() > cur.snd) {
        ans = reconstruct();
      }
      continue;
    }

    rep(i, 0, 4) {
      int x2 = cur.fst.fst + dx[i];
      int y2 = cur.fst.snd + dy[i];
      if (check(x2, y2)) {
        vis[x2][y2] = true;
        parent[x2][y2] = i;
        q.push({{x2, y2}, cur.snd + 1});
      }
    }
  }
  if (ans.size()) {
    cout << "YES\n";
    reverse(all(ans));
    cout << ans.size() << '\n';
    cout << ans << '\n';
  } else {
    cout << "NO\n";
  }
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;

  while (t--)
    run();
}

// AC, bfs, path reconstuction
