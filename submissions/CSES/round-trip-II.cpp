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

bool dfs(int v, vi2d &adj, vc &visited, vi &parent, vc &color, int &cycle_start,
         int &cycle_end) {
  color[v] = 1;
  for (int u : adj[v]) {
    if (color[u] == 0) {
      parent[u] = v;
      if (dfs(u, adj, visited, parent, color, cycle_start, cycle_end))
        return true;
    } else if (color[u] == 1) {
      cycle_end = v;
      cycle_start = u;
      return true;
    }
  }
  color[v] = 2;
  return false;
}

vi find_cycle(vi2d &g, int n) {
  vc visited(n);
  vi parent(n);
  vc color(n);
  int cycle_start, cycle_end;
  color.assign(n, 0);
  parent.assign(n, -1);
  cycle_start = -1;

  for (int v = 0; v < n; v++) {
    if (color[v] == 0 &&
        dfs(v, g, visited, parent, color, cycle_start, cycle_end))
      break;
  }

  if (cycle_start == -1) {
    return {};
  } else {
    vector<int> cycle;
    cycle.push_back(cycle_start);
    for (int v = cycle_end; v != cycle_start; v = parent[v]) cycle.push_back(v);
    cycle.push_back(cycle_start);
    reverse(cycle.begin(), cycle.end());
    return cycle;
  }
}
void run() {
  int n, m;
  cin >> n >> m;

  vi2d g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].eb(b);
  }

  auto ans = find_cycle(g, n);
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

// AC, graphs, cycle detection
