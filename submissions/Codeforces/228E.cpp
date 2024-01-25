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
const int MAXN(1'000'000);

struct SAT {
  int n;
  vi2d g, tg;
  vi vis;
  vi order, comp;
  vc assignment;
  bool solvable;
  int qtdcomp;

  SAT(int _n)
    : n(2 * _n),
      g(n),
      tg(n),
      vis(n),
      comp(n, -1),
      assignment(n / 2) {}

  void dfs1(int u) {
    vis[u] = 1;
    for (auto v : g[u]) {
      if (!vis[v]) {
        dfs1(v);
      }
    }
    order.emplace_back(u);
  }

  void dfs2(int u) {
    comp[u] = qtdcomp;
    for (auto v : tg[u]) {
      if (comp[v] == -1) {
        dfs2(v);
      }
    }
  }

  bool solve2sat() {
    for (int i = 0; i < n; i++) {
      if (!vis[i]) dfs1(i);
    }

    reverse(all(order));
    qtdcomp = 0;
    for (auto u : order) {
      if (comp[u] == -1) {
        dfs2(u);
        qtdcomp++;
      }
    }

    assignment.assign(n / 2, false);
    for (int i = 0; i < n; i += 2) {
      if (comp[i] == comp[i + 1]) {
        solvable = false;
        return false;
      }

      assignment[i / 2] = comp[i] < comp[i + 1];
    }

    solvable = 1;
    return solvable;
  }

  void add_dis(int a, bool va, int b, bool vb) {  // a V b
    va = !va, vb = !vb;
    a = (2 * a) ^ va, b = (2 * b) ^ vb;
    int nota = a ^ 1, notb = b ^ 1;
    g[nota].emplace_back(b), g[notb].emplace_back(a),
      tg[b].emplace_back(nota), tg[a].emplace_back(notb);
  }

  void add_impl(int a, bool va, int b, int vb) {  // a -> b
    add_dis(a, !va, b, vb);
  }

  void add_equiv(int a, bool va, int b,
                 bool vb) {  // a <-> b
    add_impl(a, 1, b, 1);
    add_impl(b, 1, a, 1);
    add_impl(a, 0, b, 0);
    add_impl(b, 0, a, 0);
  }

  void add_xor(int a, bool va, int b, bool vb) {  // a xor b
    add_impl(a, 1, b, 0);
    add_impl(a, 0, b, 1);
    add_impl(b, 1, a, 0);
    add_impl(b, 0, a, 1);
  }
};

auto run() {
  int n, m;
  cin >> n >> m;

  SAT st(n);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;

    if (c) {
      st.add_equiv(a, 1, b, 1);
    } else {
      st.add_xor(a, 1, b, 1);
    }
  }

  if (st.solve2sat()) {
    vi ans;
    for (int i = 0; i < n; i++) {
      if (st.assignment[i]) ans.emplace_back(i + 1);
    }
    cout << len(ans) << '\n';
    for (int i = 0; i < len(ans); i++) {
      cout << ans[i] << " \n"[i == len(ans) - 1];
    }
  } else {
    cout << "Impossible\n";
  }
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> T;

  for (int i = 1; i <= T; i++) {
    run();
  }
}
