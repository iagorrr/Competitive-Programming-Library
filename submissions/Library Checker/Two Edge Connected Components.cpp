#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define endl '\n'
#define fastio                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
// #define int long long
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
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define rep(i, begin, end)                              \
  for (__typeof(begin) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end));                  \
       i += 1 - 2 * ((begin) > (end)))

int lg2(ll x) {
  return __builtin_clzll(1) - __builtin_clzll(x);
}

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D",
// "LD", "L"}); int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}; int
// dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll OO = 1e18;
const int oo = 1e9;

int T(1);

const int maxn(3'00'000);
int tin[maxn], compId[maxn], qtdComps;
vi g[maxn], stck;
int n;
int dfs(int u, int p = -1) {
  int low = tin[u] = len(stck);
  stck.emplace_back(u);

  bool multEdge = false;
  for (auto v : g[u]) {
    if (v == p and !multEdge) {
      multEdge = 1;
      continue;
    }

    low = min(low, tin[v] == -1 ? dfs(v, u) : tin[v]);
  }

  if (low == tin[u]) {
    for (int i = tin[u]; i < len(stck); i++)
      compId[stck[i]] = qtdComps;
    stck.resize(tin[u]);
    qtdComps++;
  }

  return low;
}

void label2CC() {
  memset(compId, -1, sizeof(int) * n);
  memset(tin, -1, sizeof(int) * n);

  stck.reserve(n);
  for (int i = 0; i < n; i++) {
    if (tin[i] == -1) dfs(i);
  }
}

auto run() {
  int m;
  cin >> n >> m;

  for (int i = 0, a, b; i < m; i++) {
    cin >> a >> b;
    if (a != b) {
      g[a].eb(b);
      g[b].eb(a);
    }
  }

  label2CC();

  vi2d compsVertex(qtdComps);
  for (int i = 0; i < n; i++) {
    compsVertex[compId[i]].eb(i);
  }

  cout << qtdComps << '\n';
  for (auto vertexs : compsVertex) {
    cout << len(vertexs);
    for (auto i : vertexs) cout << ' ' << i;
    cout << '\n';
  }
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> T;

  for (int t = 1; t <= T; t++) {
    run();
  }
}

// AC, bridge tree component, 2-edge connected component
