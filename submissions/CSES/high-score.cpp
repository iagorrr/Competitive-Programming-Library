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

const ll oo = 1e9 * 2500;
using adj = vector<vector<pair<int, ll>>>;
ll findc(int u, int n, int source, vc &vis, int &has1, int &hasn, adj &g,
         vll &dist) {
  vis[u] = 1;
  has1 |= u == 0;
  hasn |= u == n - 1;

  for (auto [v, d] : g[u]) {
    if (v == source) {
      dist[u] = max(dist[u], d);
      continue;
    }

    if (vis[v] == 1) {
      continue;
    }

    if (vis[v] == 2) {
      dist[u] = max(dist[u], dist[v] + d);
    } else {
      ll d2 = findc(v, n, source, vis, has1, hasn, g, dist);
      if (d2 != -oo) {
        dist[u] = max(dist[u], d2 + d);
      }
    }
  }
  vis[u] = 2;
  return dist[u];
}

bool bellman_ford(const vector<vector<pair<int, ll>>> &g, int s,
                  vector<ll> &dist) {
  int n = (int)g.size();
  dist.assign(n, -oo);

  vector<int> count(n);
  vector<char> in_queue(n);
  queue<int> q;

  dist[s] = 0;
  q.push(s);
  in_queue[s] = true;

  while (not q.empty()) {
    int cur = q.front();
    q.pop();
    in_queue[cur] = false;

    for (auto [to, w] : g[cur]) {
      if (dist[cur] + w > dist[to]) {
        dist[to] = dist[cur] + w;
        if (not in_queue[to] and count[to] < n) {
          q.push(to);
          in_queue[to] = true;
          count[to]++;
        }
      }
    }
  }

  return true;
}
void run() {
  int n, m;
  cin >> n >> m;

  adj g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    ll x;
    cin >> u >> v >> x;
    u--, v--;
    g[u].emplace_back(v, x);
  }

  vc reach1(n), reachn(n), from1(n), fromn(n), hascyclepositive(n);

  for (int i = 0; i < n; i++) {
    vll dist(n, -oo);
    vc vis(n, 0);  // ve se isso aqui ta certo
    int has1 = 0, hasn = 0;

    ll D = findc(i, n, i, vis, has1, hasn, g, dist);
    // cout << "i: " << i << " D: " << D << endl;
    // for (int j = 0; j < n; j++) {
    //   cout << "j: " << j << " dist[j]: " << dist[j] << endl;
    // }
    reach1[i] = has1;
    reachn[i] = hasn;
    hascyclepositive[i] = D > 0;

    if (i == 0) {
      for (int j = 0; j < n; j++) {
        from1[j] = vis[j] > 0;
      }
    }

    if (i == n - 1) {
      for (int j = 0; j < n; j++) {
        fromn[j] = vis[j] > 0;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (hascyclepositive[i]) {
      if (from1[i] and reachn[i]) {
        // cout << "caso 1 deumerda no " << i << endl;
        cout << -1 << endl;
        return;
      }
      if (fromn[i] and reach1[i]) {
        // cout << "caso 2 deu merda no " << i << endl;
        cout << -1 << endl;
        return;
      }
    }
  }

  vll dist(n);
  bellman_ford(g, 0, dist);
  cout << dist[n - 1] << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, graphs, bellman ford
