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

const ll INF = 1e18;
void dfs(int u, int p, vi &c, vi &c2, int s, vi2d &g, int &ans) {
  c2[u] = s;
  if (c2[u] != c[u]) {
    s = c[u];
    c2[u] = s;
    ans++;
  }

  for (auto &v : g[u])
    if (v != p) {
      dfs(v, u, c, c2, s, g, ans);
    }
}
void run() {
  int n;
  cin >> n;
  vi2d g(n + 1);
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    g[p].pb(i);
    g[i].pb(p);
  }
  vi c(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }

  vi c2(n + 1, -1);  // current color.
  queue<int> q;
  q.push(1);
  int ans = 0;
  dfs(1, -1, c, c2, -1, g, ans);

  cout << ans << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, graphs, trees, dfs/bfs
