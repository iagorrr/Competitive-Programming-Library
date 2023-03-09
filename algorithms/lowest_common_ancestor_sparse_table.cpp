// iagorrr ;)
// https://cp-algorithms.com/graph/lca.html#implementation
#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(a)      \
  for (auto &x : a) \
  cin >> x
#define all(a) a.begin(), a.end()

int fastlog2(ll x)
{
  ull i = x;
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}
template <typename T>
class SparseTable
{
public:
  int N;
  int K;
  vector<vector<T>> st;
  SparseTable(vector<T> vs) : N((int)vs.size()), K(fastlog2(N) + 1), st(K + 1, vector<T>(N + 1))
  {
    copy(vs.begin(), vs.end(), st[0].begin());

    for (int i = 1; i <= K; ++i)
      for (int j = 0; j + (1 << i) <= N; ++j)
        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
  }
  SparseTable() {}
  T RMQ(int l, int r)
  {
    int i = fastlog2(r - l + 1);
    return min(st[i][l], st[i][r - (1 << i) + 1]);
  }
};
class LCA
{
public:
  int p;
  int n;
  vi first;
  vector<char> visited;
  vi vertices;
  vi height;
  SparseTable<int> st;

  LCA(const vector<vi> &g) : p(0), n((int)g.size()), first(n + 1), visited(n + 1, 0), height(n + 1)
  {
    build_dfs(g, 1, 1);
    st = SparseTable<int>(vertices);
  }

  void build_dfs(const vector<vi> &g, int u, int hi)
  {
    visited[u] = true;
    height[u] = hi;
    first[u] = vertices.size();
    vertices.push_back(u);
    for (auto uv : g[u])
    {
      if (!visited[uv])
      {
        build_dfs(g, uv, hi + 1);
        vertices.push_back(u);
      }
    }
  }

  int lca(int a, int b)
  {
    int l = min(first[a], first[b]);
    int r = max(first[a], first[b]);
    return st.RMQ(l, r);
  }
};

void run()
{
  int n = 7;
  vector<vi> g(n + 1);

  g[1].push_back(2);
  g[1].push_back(3);
  g[1].push_back(4);
  g[2].push_back(5);
  g[2].push_back(6);
  g[2].push_back(1);
  g[5].push_back(2);
  g[6].push_back(2);
  g[3].push_back(1);
  g[4].push_back(1);
  g[4].push_back(7);
  g[7].push_back(4);

  LCA lca(g);

  cout << "vertices: ";
  for (auto v : lca.vertices)
    cout << v << " ";
  cout << '\n';

  cout << "heights:  ";
  for (auto v : lca.vertices)
    cout << lca.height[v] << " ";
  cout << '\n';

  while (true)
  {
    int l, r;
    cin >> l >> r;
    cout << "lca(" << l << "," << r << "): " << lca.lca(l, r) << '\n';
  }
}
int32_t main(void)
{
  // fastio;
  int t;
  t = 1;

  while (t--)
    run();
}
