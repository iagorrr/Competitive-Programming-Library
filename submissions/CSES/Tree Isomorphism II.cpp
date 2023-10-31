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

map<vector<int>, int> mphash;

struct Tree {
  int n;
  vi2d g;
  vi sz, cs;

  Tree(int n_) : n(n_), g(n), sz(n) {}

  void add_edge(int u, int v) {
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  void dfs_centroid(int v, int p) {
    sz[v] = 1;
    bool cent = true;
    for (int u : g[v])
      if (u != p) {
        dfs_centroid(u, v);
        sz[v] += sz[u];
        cent &= not(sz[u] > n / 2);
      }
    if (cent and n - sz[v] <= n / 2) cs.push_back(v);
  }

  int fhash(int v, int p) {
    vi h;
    for (int u : g[v])
      if (u != p) h.push_back(fhash(u, v));
    sort(all(h));
    if (!mphash.count(h)) mphash[h] = mphash.size();
    return mphash[h];
  }

  ll thash() {
    cs.clear();
    dfs_centroid(0, -1);
    if (cs.size() == 1) return fhash(cs[0], -1);
    ll h1 = fhash(cs[0], cs[1]), h2 = fhash(cs[1], cs[0]);
    return (min(h1, h2) << 30ll) + max(h1, h2);
  }
};

int N;
auto solve() {
  Tree t1(N), t2(N);

  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    t1.add_edge(a, b);
  }

  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    t2.add_edge(a, b);
  }

  vector<string> ans({"NO", "YES"});
  cout << ans[(t1.thash() == t2.thash())] << endl;
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    while (cin >> N) {
      solve();
    }
  }
}

// AC, graphs, trees, isomorphism
