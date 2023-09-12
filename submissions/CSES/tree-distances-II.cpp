#include <bits/stdc++.h>

#include <numeric>
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

const ll oo = 1e18;

void getRoot(int u, int p, vi2d &g, vll &d, vll &cnt) {
  for (int i = 0; i < len(g[u]); i++) {
    int v = g[u][i];
    if (v == p) continue;
    getRoot(v, u, g, d, cnt);
    d[u] += d[v] + cnt[v];
    cnt[u] += cnt[v];
  }
}

void dfs(int u, int p, vi2d &g, vll &cnt, vll &ansd, int n) {
  for (int i = 0; i < len(g[u]); i++) {
    int v = g[u][i];
    if (v == p) continue;

    ansd[v] = ansd[u] - cnt[v] + (n - cnt[v]);
    dfs(v, u, g, cnt, ansd, n);
  }
}
vll fromToAll(vi2d &g, int n) {
  vll d(n);
  vll cnt(n, 1);
  getRoot(0, -1, g, d, cnt);

  vll ansdist(n);
  ansdist[0] = d[0];

  dfs(0, -1, g, cnt, ansdist, n);
  return ansdist;
}
void run() {
  int n;
  cin >> n;

  vi2d g(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].pb(b);
    g[b].pb(a);
  }

  auto ans = fromToAll(g, n);

  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n - 1];
  }
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  while (t--) run();
}
