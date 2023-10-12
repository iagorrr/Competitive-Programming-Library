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
const int MAXN(100000);

vi color(MAXN);
vi2d g(MAXN);
vi allcls(MAXN);
vi ans(MAXN);
map<pii, int> id;
// small to large
vi sz(MAXN);
void getsz(int u, int p = -1) {
  dbg(u);
  sz[u] = 1;
  for (auto v : g[u])
    if (v != p) {
      getsz(v, u);
      sz[u] += sz[v];
    }
}
map<int, int> cls[MAXN];
void stl(int u, int p = -1) {
  dbg(u, p);
  int bv = -1;
  for (auto v : g[u]) {
    if (v == p) continue;
    if (bv == -1 or sz[v] > sz[bv]) bv = v;
  }

  if (bv == -1) {
    cls[u][color[u]] = 1;
    return;
  }

  stl(bv, u);
  int cid = id[{bv, u}];
  for (auto [c, qtd] : cls[bv]) {
    ans[cid] += qtd * (allcls[c] - qtd);
  }
  swap(cls[bv], cls[u]);
  cls[u][color[u]]++;

  for (auto v : g[u]) {
    if (v == p or v == bv) continue;
    stl(v, u);
    cid = id[{v, u}];
    for (auto [c, qtd] : cls[v]) {
      ans[cid] += qtd * (allcls[c] - qtd);
      cls[u][c] += qtd;
    }
  }
}
void stl() {
  getsz(0);
  stl(0);
}

auto solve() {
  int N;
  cin >> N;

  dbg(N);
  for (int i = 0; i < N; i++) {
    cin >> color[i];
    color[i]--;
    allcls[color[i]]++;
  }

  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
    id[{u, v}] = i;
    id[{v, u}] = i;
  }

  stl();

  for (int i = 0; i < N - 1; i++) cout << ans[i] << " \n"[i == N - 1];
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

// AC, trees, small to large
