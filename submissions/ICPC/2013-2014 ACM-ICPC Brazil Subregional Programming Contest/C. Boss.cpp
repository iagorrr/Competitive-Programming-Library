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

const int MAXN(500);
int N, M, I;
vll KS(MAXN);
vi2d G(MAXN);
vi W(MAXN);

vector<char> vis(MAXN);
string query(int e) {
  if (G[e].empty()) return "*";
  fill(all(vis), false);
  ll y = oo;

  queue<int> q;
  vis[e] = true;
  for (auto v : G[e]) {
    if (vis[v]) continue;
    vis[v] = true;
    q.emplace(v);
  }
  while (not q.empty()) {
    auto u = q.front();
    q.pop();

    y = min(y, KS[u]);

    for (auto v : G[u]) {
      if (vis[v]) continue;
      vis[v] = true;
      q.emplace(v);
    }
  }

  return y == oo ? "*" : to_string(y);
}
auto solve() {
  for (int i = 0; i < N; i++) {
    W[i] = i;
    cin >> KS[i];
    G[i].clear();
  }

  for (int i = 0; i < M; i++) {
    int xi, yi;
    cin >> xi >> yi;
    yi--, xi--;
    G[yi].emplace_back(xi);
  }

  for (int i = 0; i < I; i++) {
    char op;
    cin >> op;

    switch (op) {
      case 'T':
        int a, b;
        cin >> a >> b;
        a--, b--;
        swap(KS[W[a]], KS[W[b]]);
        swap(W[a], W[b]);
        break;

      default:
        int e;
        cin >> e;
        e--;
        cout << query(W[e]) << endl;
        break;
    }
  }
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> T;

  while (cin >> N >> M >> I) solve();
}

// AC, graphs, dfs/bfs
