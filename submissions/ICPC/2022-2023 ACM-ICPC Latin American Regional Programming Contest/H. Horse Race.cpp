#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...) 42
#endif
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int)__x.size()
using ll = long long;
using ull = unsigned long long;
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
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D", "LD", "L"});
// int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
// int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll oo = 1e18;

struct maxflow {
  int n;
  vi2d g;
  vll2d cps;
  vi ps;
  vector<vector<char>> isedge;

  maxflow(int _n)
    : n(_n), g(n), cps(n, vll(n)), ps(n), isedge(n, vc(n)) {}

  void add(int u, int v, ll c, bool set = true) {
    g[u].emplace_back(v);
    g[v].emplace_back(u);
    cps[u][v] = cps[u][v] * (!set) + c;
    isedge[u][v] = true;
  }

  ll bfs(int s, int t) {
    fill(all(ps), -1);
    ps[s] = -2;
    queue<pair<ll, int>> q;
    q.emplace(oo, s);

    while (!q.empty()) {
      auto [flow, cur] = q.front();
      q.pop();

      for (auto next : g[cur]) {
        if (ps[next] == -1 and cps[cur][next]) {
          ps[next] = cur;
          ll new_flow = min(flow, cps[cur][next]);
          if (next == t) return new_flow;
          q.emplace(new_flow, next);
        }
      }
    }

    return 0ll;
  }

  ll flow(int s, int t) {
    ll flow = 0;
    ll new_flow;

    while ((new_flow = bfs(s, t))) {
      flow += new_flow;
      int cur = t;
      while (cur != s) {
        int prev = ps[cur];
        cps[prev][cur] -= new_flow;
        cps[cur][prev] += new_flow;
        cur = prev;
      }
    }

    return flow;
  }

  vector<pii> get_used() {
    vector<pii> used;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (isedge[i][j] and cps[i][j] == 0) used.emplace_back(i, j);
      }
    }
    return used;
  }
};

const int maxn(300 * 4);
int appears[maxn];
vi2d canbe(maxn, vi(maxn, 0));
vi maxcanbe(maxn, 1);
map<string, int> strtoid;
map<int, string> idtostr;

auto solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    strtoid[tmp] = i * 2 + 1;
    idtostr[i * 2 + 1] = tmp;
  }

  int m;
  cin >> m;
  while (m--) {
    int k, w;
    cin >> k >> w;
    appears[w]++;
    while (k--) {
      string str;
      cin >> str;
      int curid = strtoid[str];
      canbe[curid][w]++;
      maxcanbe[curid] = max(maxcanbe[curid], w);
    }
  }

  for (int i = 0; i < n; i++) {
    int curid = i * 2 + 1;
    for (int j = 1; j < maxcanbe[curid]; j++) {
      canbe[curid][j] = -1;
    }

    for (int j = maxcanbe[curid]; j <= n; j++) {
      if (appears[j] != canbe[curid][j]) canbe[curid][j] = -1;
    }
  }

  maxflow mf(n * 4 + 1);
  int source = 0, sink = n * 4;
  for (int i = 0; i < n; i++) {
    int strid = i * 2 + 1;
    mf.add(source, strid, 1);
    for (int j = 1; j <= n; j++) {
      if (canbe[strid][j] != -1) mf.add(strid, j * 2, 1);
    }
  }

  for (int j = 1; j <= n; j++) {
    mf.add(j * 2, sink, 1);
  }

  mf.flow(source, sink);

  auto edg = mf.get_used();
  vector<pair<int, string>> ans;
  for (auto &[u, v] : edg) {
    if (u == source or v == source) continue;
    if (u == sink or v == sink) continue;
    ans.emplace_back(v / 2, idtostr[u]);
  }
  sort(all(ans));
  for (auto &[pos, str] : ans) {
    cout << str << ' ';
  }
  cout << endl;
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  int t;
  t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}

// AC, graphs, maxflow
