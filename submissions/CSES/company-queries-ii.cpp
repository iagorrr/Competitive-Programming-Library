#include <bits/stdc++.h>
using namespace std;
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
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

const ll oo = 1e18;

int fastlog2(ll x) {
  ull i = x;
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}
template <typename T>
class SparseTable {
 public:
  int N;
  int K;
  vector<vector<T>> st;
  SparseTable(vector<T> vs)
    : N(len(vs)), K(fastlog2(N) + 1), st(K + 1, vector<T>(N + 1)) {
    copy(all(vs), st[0].begin());

    for (int i = 1; i <= K; ++i)
      for (int j = 0; j + (1 << i) <= N; ++j)
        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
  }
  SparseTable() {}
  T RMQ(int l, int r) {
    int i = fastlog2(r - l + 1);
    return min(st[i][l], st[i][r - (1 << i) + 1]);
  }
};
class LCA {
 public:
  int p;
  int n;
  vi first;
  vc visited;
  vi vertices;
  vi height;
  SparseTable<int> st;

  LCA(const vi2d &g)
    : p(0), n(len(g)), first(n + 1), visited(n + 1, 0), height(n + 1) {
    build_dfs(g, 0, 1);
    st = SparseTable<int>(vertices);
  }

  void build_dfs(const vi2d &g, int u, int hi) {
    visited[u] = true;
    height[u] = hi;
    first[u] = len(vertices);
    vertices.pb(u);
    for (auto uv : g[u]) {
      if (!visited[uv]) {
        build_dfs(g, uv, hi + 1);
        vertices.pb(u);
      }
    }
  }

  int lca(int a, int b) {
    int l = min(first[a], first[b]);
    int r = max(first[a], first[b]);
    return st.RMQ(l, r);
  }
};
void run() {
  int n, q;
  cin >> n >> q;

  vi2d g(n);
  for (int i = 1; i < n; i++) {
    int boss;
    cin >> boss;
    boss--;
    g[boss].eb(i);
  }

  LCA st(g);
  while (q--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    cout << st.lca(a, b) + 1 << endl;
  }
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, trees, lowest common ancestor
