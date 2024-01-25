#include <bits/stdc++.h>
#define eb emplace_back
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define len(x) (int)x.size()
#define int long long

using namespace std;
using pii = pair<int, int>;

/*
   double distance at each step ?
   root the tree at the radius
 */
const int MAXN(30);
vector<int> G[MAXN];
int dg[MAXN];
int N;

pair<int, int> ans[MAXN];
void buildAns(int u, int x, int y, int dir, int d = 30,
              int p = -1) {
  d--;
  ans[u] = {x, y};

  int dx[] = {0, -1, 0, 1};
  int dy[] = {-1, 0, 1, 0};

  int i = 0;
  for (auto v : G[u])
    if (v != p) {
      while ((1 << i) & dir) {
        i = (i + 1) % 4;
      }
      dir |= (1 << i);
      int j = (i + 2) % 4;
      buildAns(v, x + (1 << d) * dx[i],
               y + (1 << d) * dy[i], (1 << j), d, u);
    }
}

void run() {
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    dg[a]++, dg[b]++;
    G[a].eb(b), G[b].eb(a);
    if (dg[a] > 4) {
      cout << "NO\n";
      return;
    }
  }

  buildAns(0, 0, 0, 0);

  cout << "YES\n";
  for (int i = 0; i < N; i++) {
    cout << ans[i].ff << ' ' << ans[i].ss << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  run();
}
