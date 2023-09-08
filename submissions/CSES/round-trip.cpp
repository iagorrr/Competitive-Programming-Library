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

const ll oo = 1e18;

bool dfs(int v, int p, vi2d &g, vc &vis, vi &par, int &s, int &e) {
  vis[v] = true;
  for (int u : g[v]) {
    if (u == p) continue;
    if (vis[u]) {
      e = v;
      s = u;
      return true;
    }
    par[u] = v;
    if (dfs(u, par[u], g, vis, par, s, e)) return true;
  }
  return false;
}

vi find_cycle(vi2d &g, int n) {
  vc vis(n, false);
  vi par(n, -1);
  int end, start = -1;

  for (int v = 0; v <= n - 1; v++) {
    if (!vis[v] and dfs(v, par[v], g, vis, par, start, end)) break;
  }

  if (start == -1) {
    return {};
  } else {
    vi cycle;
    cycle.push_back(start);
    for (int v = end; v != start; v = par[v]) cycle.push_back(v);
    cycle.push_back(start);

    return cycle;
  }
}
void run() {
  int n, m;
  cin >> n >> m;

  vi2d adj(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].eb(b);
    adj[b].eb(a);
  }
  auto ans = find_cycle(adj, n);
  if (ans.empty())
    cout << "IMPOSSIBLE\n";
  else {
    cout << len(ans) << endl;
    for (auto &ai : ans) cout << ai + 1 << ' ';
    cout << endl;
  }
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, cycle finding
