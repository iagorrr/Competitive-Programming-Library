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

vector<string> dir({"LU", "U", "RU", "R", "RD", "D", "LD", "L"});
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
const ll oo = 1e18;
const int maxn = 1e5;
vll cs(maxn);
vi2d g(maxn);

struct DSU {
  vi ps;
  vi size;
  vector<set<int>> sts;
  DSU(int N) : ps(N + 1), size(N, 1), sts(N) {
    iota(all(ps), 0);
    for (int i = 0; i < N; i++) sts[i].insert(i);
  }
  int find_set(int x) { return ps[x] == x ? x : ps[x] = find_set(ps[x]); }
  bool same_set(int x, int y) { return find_set(x) == find_set(y); }
  void union_set(int x, int y) {
    if (same_set(x, y)) return;

    int px = find_set(x);
    int py = find_set(y);

    if (size[px] < size[py]) swap(px, py);

    ps[py] = px;
    size[px] += size[py];
    sts[px].merge(sts[py]);
  }
};

void run() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> cs[i];
  }

  DSU dsu(n);
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    dsu.union_set(a, b);
    g[a].eb(b);
    g[b].eb(a);
  }

  vll cs2(n, oo);
  set<ll> done;
  for (int i = 0; i < n; i++) {
    auto p = dsu.find_set(i);
    if (done.count(p)) continue;
    done.insert(p);
    for (auto ei : dsu.sts[p]) {
      cs2[p] = min(cs2[p], cs[p]);
    }
  }

  ll ans = 0;
  for (auto v : done) ans += cs2[v];
  cout << ans << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, graphs, bfs/dfs, dsu, data structures
