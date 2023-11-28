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
int lg2(ll x) {
  return __builtin_clzll(1) - __builtin_clzll(x);
}

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D",
// "LD", "L"}); int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}; int
// dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll oo = 1e18;
int T(1);

/*
 * Generate a maximum spanning tree
 * me = the minimum edge in the maximum spanning tree
 * than in each trip you can take me-1 passengers, as the
 * driver is also included
 * */
const int MAXN(1'00'000);
ll N, R, S, E, P;
vector<pair<ll, int>> G[MAXN];
vector<vector<pair<ll, int>>> prim(vi s = vi(1, 0)) {
  using a3 = tuple<ll, int, int>;
  priority_queue<a3> pq;
  vector<char> ingraph(MAXN);
  int ingraphcnt(0);
  vector<vector<pair<ll, int>>> g2(N);
  for (auto si : s) {
    ingraphcnt++;
    ingraph[si] = true;
    for (auto &[w, v] : G[si]) pq.emplace(w, si, v);
  }

  while (ingraphcnt < N) {
    ll w;
    int v, u;

    do {
      tie(w, u, v) = pq.top();
      pq.pop();
    } while (not pq.empty() and ingraph[v]);

    ingraph[v] = true, ingraphcnt++;
    g2[u].emplace_back(w, v), g2[v].emplace_back(w, u);

    for (auto &[w2, v2] : G[v]) {
      pq.emplace(w2, v, v2);
    }
  }

  return g2;
}

ll bfs(vector<vector<pair<ll, int>>> &g) {
  vi ps(N, -1);
  vector<char> vis(N);
  queue<int> q;
  q.emplace(S);
  vis[S] = true;

  while (not q.empty()) {
    auto u = q.front();
    q.pop();

    for (auto [w, v] : g[u]) {
      if (vis[v]) continue;
      ps[v] = u;
      vis[v] = true;
      q.emplace(v);
    }
  }

  vll2d ds(N, vll(N, oo));
  for (int i = 0; i < N; i++) {
    for (auto &[w, v] : g[i]) {
      ds[i][v] = w;
    }
  }

  int cur = E;
  ll mine = oo;
  while (cur != -1) {
    int prev = ps[cur];
    if (prev != -1) {
      mine = min(mine, ds[cur][prev]);
    }
    cur = prev;
  }

  return mine;
}

auto solve() {
  for (int i = 0; i < N; i++) G[i].clear();

  for (int i = 0; i < R; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    G[a].emplace_back(c, b), G[b].emplace_back(c, a);
  }
  cin >> S >> E >> P;
  S--, E--;

  auto g2 = prim();

  ll mine = bfs(g2);

  mine--;
  return (P + mine - 1ll) / mine;
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> T;

  int a = 1;
  while (cin >> N >> R) {
    if (N and R) {
      cout << "Scenario #" << a++ << endl;
      cout << "Minimum Number of Trips = " << solve()
           << endl << endl;
    } else
      break;
  }
}

/*
 * AC
 * Graphs
 * MST
 * bfs/dfs
 * https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&ved=2ahUKEwig45zegeeCAxWnLLkGHYe8DQMQFnoECAsQAQ&url=https%3A%2F%2Fonlinejudge.org%2Fexternal%2F100%2F10099.pdf&usg=AOvVaw3PLg36jVp5NAKe1G3AuVg9&opi=89978449
 * */
