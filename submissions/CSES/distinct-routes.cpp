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
using vc2d = vector<vc>;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

const ll oo = 1e17;

ll bfs(int s, int t, vi2d &g, vll2d &capacity, vi &parent) {
  fill(all(parent), -1);
  parent[s] = -2;
  queue<pair<ll, int>> q;
  q.push({oo, s});

  while (!q.empty()) {
    auto [flow, cur] = q.front();
    q.pop();

    for (auto next : g[cur]) {
      if (parent[next] == -1 and capacity[cur][next]) {
        parent[next] = cur;
        ll new_flow = min(flow, capacity[cur][next]);
        if (next == t) return new_flow;
        q.push({new_flow, next});
      }
    }
  }

  return 0ll;
}

ll maxflow(int s, int t, int n, vi2d &g, vll2d &capacity) {
  ll flow = 0;
  vi parent(n);
  ll new_flow;

  while ((new_flow = bfs(s, t, g, capacity, parent))) {
    flow += new_flow;
    int cur = t;
    while (cur != s) {
      int prev = parent[cur];
      capacity[prev][cur] -= new_flow;
      capacity[cur][prev] += new_flow;
      cur = prev;
    }
  }

  return flow;
}

void dfs(int u, int t, vi2d &g, vc2d &vis, vc2d &isedge, vll2d &capacity,
         vi &route,

         vi2d &routes) {
  route.eb(u);
  if (u == t) {
    routes.emplace_back(route);
    route.pop_back();
    return;
  }
  for (auto &v : g[u]) {
    if (capacity[u][v] == 0 and isedge[u][v] and not vis[u][v]) {
      vis[u][v] = true;
      dfs(v, t, g, vis, isedge, capacity, route, routes);
      route.pop_back();
      return;
    }
  }
}
vi2d disjoint_paths(vi2d &g, vll2d &capacity, vc2d &isedge, int s, int t,
                    int n) {
  ll mf = maxflow(s, t, n, g, capacity);
  vi2d routes;
  vi route;
  vc2d vis(n + 1, vc(n + 1));
  for (int i = 0; i < (int)mf; i++)
    dfs(s, t, g, vis, isedge, capacity, route, routes);
  return routes;
}
void run() {
  int n, m;
  cin >> n >> m;

  vi2d g(n);
  vll2d capacity(n, vll(n));
  vc2d used(n, vc(n));
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].eb(b);
    g[b].eb(a);
    capacity[a][b]++;
    used[a][b] = true;
  }

  auto ans = disjoint_paths(g, capacity, used, 0, n - 1, n);
  cout << len(ans) << endl;

  for (auto &ansi : ans) {
    cout << len(ansi) << endl;
    for (auto &ai : ansi) {
      cout << ai + 1 << ' ';
    }
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

// AC, maxflow, distinct disjoint paths
