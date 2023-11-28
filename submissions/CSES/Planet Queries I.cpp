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

const int MAXN(2 * 1'00'000);
int N, Q;

vi G(MAXN);

struct SuccessorGraph {
  vi2d paths;
  vi path_num, pos, is_cycle;

  SuccessorGraph(const vi &v)
    : path_num(len(v)), pos(len(v)) {
    paths.reserve(len(v));
    is_cycle.reserve(len(v));

    vector<char> vis(len(v));
    for (auto i : topological_order(v)) {
      if (vis[i]) continue;

      vi path;
      int cur;
      for (cur = i; not vis[cur]; cur = v[cur]) {
        path.push_back(cur);
        vis[cur] = 1;
      }

      int cycle_start = 0;
      for (; cycle_start < (int)path.size() and
             path[cycle_start] != cur;
           cycle_start++)
        ;

      if (cycle_start > 0) {
        paths.emplace_back();
        for (int j = 0; j < cycle_start; j++) {
          paths.back().push_back(path[j]);
          pos[path[j]] = j;
          path_num[path[j]] = len(paths) - 1;
        }
        paths.back().push_back(cur);
        is_cycle.push_back(false);
      }

      if (cycle_start < len(path)) {
        paths.emplace_back();
        for (int j = cycle_start; j < len(path); j++) {
          paths.back().push_back(path[j]);
          pos[path[j]] = j - cycle_start;
          path_num[path[j]] = len(paths) - 1;
        }
        is_cycle.push_back(true);
      }
    }
  }

  const vi &path(int cur) const {
    return paths[path_num[cur]];
  }

  int kth_pos(int cur, ll k) const {
    while (not is_cycle[path_num[cur]]) {
      auto &p = path(cur);
      int remain = len(p) - pos[cur] - 1;
      if (k <= remain) return p[pos[cur] + k];
      cur = p.back();
      k -= remain;
    }

    auto &p = path(cur);
    return p[(pos[cur] + k) % len(p)];
  }

  // {element, number_of_moves}
  pii go_to_cycle(int cur) const {
    int moves = 0;
    while (not is_cycle[path_num[cur]]) {
      auto &p = path(cur);
      moves += len(p) - pos[cur] - 1;
      cur = p.back();
    }
    return {cur, moves};
  }

  // min cost to reach dest from cur
  int reach(int cur, int dest) const {
    int moves = 0;
    while (not is_cycle[path_num[cur]] and
           path_num[cur] != path_num[dest]) {
      auto &p = path(cur);
      moves += len(p) - pos[cur] - 1;
      cur = p.back();
    }

    if (path_num[cur] != path_num[dest]) return -1;

    if (pos[cur] <= pos[dest])
      return moves + pos[dest] - pos[cur];

    if (not is_cycle[path_num[cur]]) return -1;

    return moves + pos[dest] + len(path(cur)) - pos[cur];
  }

 private:
  void topological_order(const vi &g, vc &vis, vi &order,
                         int u) {
    vis[u] = true;
    if (not vis[g[u]])
      topological_order(g, vis, order, g[u]);
    order.push_back(u);
  }

  vector<int> topological_order(const vi &g) {
    vc vis(len(g), false);
    vi order;
    for (auto i = 0; i < len(g); i++)
      if (not vis[i]) topological_order(g, vis, order, i);

    reverse(all(order));
    return order;
  }
};
auto solve() {
  cin >> N >> Q;
  G.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> G[i];
    G[i]--;
  }
  SuccessorGraph sg(G);
  while (Q--) {
    int u, k;
    cin >> u >> k;
    u--;
    cout << sg.kth_pos(u, k) + 1 << endl;
  }
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> T;

  for (int i = 1; i <= T; i++) {
    solve();
  }
}

/*
 * AC
 * grpahs
 * successor graph
 * binary lifting
 * */
