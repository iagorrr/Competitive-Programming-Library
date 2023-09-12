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

void getRoot(int u, int p, vi2d &g, vll2d &sd, vi2d &sc, vll &d, vll &cnt) {
  for (int i = 0; i < len(g[u]); i++) {
    int v = g[u][i];
    if (v == p) continue;
    getRoot(v, u, g, sd, sc, d, cnt);
    sd[u][i] = 1 + d[v] + cnt[v];
    sc[u][i] = cnt[v] + 1;
    d[u] += 1 + d[v] + cnt[v];
    cnt[u] += cnt[v] + 1;
  }
}

void dfs(int u, int p, vi2d &g, vll2d &sd, vi2d &scnt, vll &d, vll &cnt,
         vll &ansd, int n) {
  for (int i = 0; i < len(g[u]); i++) {
    int v = g[u][i];
    if (v == p) continue;

    ansd[v] = ansd[u] - scnt[u][i] + (n - scnt[u][i]);
    dfs(v, u, g, sd, scnt, d, cnt, ansd, n);
  }
}
vll fromToAll(vi2d &g, int n) {
  vll2d sd(n);
  vi2d scnt(n);
  vll d(n);
  vll cnt(n);
  for (int i = 0; i < n; i++) {
    sd[i] = vll(len(g[i]));
    scnt[i] = vi(len(g[i]));
  }
  getRoot(0, -1, g, sd, scnt, d, cnt);

  vll ansdist(n);
  ansdist[0] = d[0];
  dfs(0, -1, g, sd, scnt, d, cnt, ansdist, n);
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

// AC, trees, dfs
