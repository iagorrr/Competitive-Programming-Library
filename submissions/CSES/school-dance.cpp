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

const ll oo = 1e17;
using graph = vector<set<int>>;
ll bfs(int s, int t, graph &g, vll2d &capacity, vi &parent) {
  fill(all(parent), -1);
  parent[s] = -2;
  queue<pair<ll, int>> q;
  q.push({1, s});

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

ll maxflow(int s, int t, int n, graph &g, vll2d &capacity) {
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

void run() {
  int n, m, k;
  cin >> n >> m >> k;

  // ss = 0, st = n+m+1
  // sources goes from [1,n] and sinks form [n+1, n+m].
  vll2d capacity(n + m + 2, vll(n + m + 2));
  vll2d isedge(n + m + 2, vll(n + m + 2));
  graph g(n + m + 2);
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;

    g[a].insert(n + b);
    g[n + b].insert(a);
    capacity[a][n + b] = 1;
    isedge[a][n + b] = true;
  }

  for (int i = 1; i <= n; i++) {
    g[0].insert(i);
    g[i].insert(0);
    capacity[0][i] = 1;
  }

  for (int i = n + 1; i <= n + m; i++) {
    g[i].insert(n + m + 1);
    g[n + m + 1].insert(i);
    capacity[i][n + m + 1] = 1;
  }

  maxflow(0, n + m + 1, m + n + 2, g, capacity);

  vii ans;
  for (int i = 1; i <= n; i++) {
    for (auto j : g[i]) {
      if (isedge[i][j] and capacity[i][j] == 0) {
        ans.emplace_back(i, j);
      }
    }
  }

  cout << len(ans) << endl;
  for (auto &[i, j] : ans) {
    cout << i << ' ' << j - n << endl;
  }
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, maxflow, mult source and mult sink
