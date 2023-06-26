// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);
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
ll n, m;
vs grid(1000);
int rooms = 0;

void flood_fill(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '#')
    return;
  grid[x][y] = '#';
  flood_fill(x + 1, y);
  flood_fill(x - 1, y);
  flood_fill(x, y + 1);
  flood_fill(x, y - 1);
}

void run() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '#')
        continue;
      rooms++;
      flood_fill(i, j);
    }
  }
  cout << rooms << '\n';
}

int32_t main(void) {
  fastio;
  int t;
  t = 1;

  while (t--)
    run();
}

// AC, flood fill
