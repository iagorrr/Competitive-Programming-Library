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
const int maxn(2 * 1e5);
struct DSU {
  vi ps;
  vi size;
  vector<unordered_set<int>> sts;
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
DSU dsum(maxn), dsdois(maxn), dstres(maxn);

void run() {
  int v, n, m;
  cin >> v >> n >> m;

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    dsum.union_set(a, b);
  }

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    dsdois.union_set(a, b);
  }

  // set<int> done;
  // for (int i = 0; i < v; i++) {
  //   int u = dsum.find_set(i);
  //   if (done.count(u)) continue;
  //   done.insert(u);
  //
  //   for (auto ei : dsum.sts[u]) cout << ei + 1 << ' ';
  //   cout << endl;
  // }
  //
  // cout << "dois: \n";
  // done.clear();
  // for (int i = 0; i < v; i++) {
  //   int u = dsdois.find_set(i);
  //   if (done.count(u)) continue;
  //   done.insert(u);
  //
  //   for (auto ei : dsdois.sts[u]) cout << ei + 1 << ' ';
  //   cout << endl;
  // }
  //
  map<pair<int, int>, vector<int>> remap;
  for (int i = 0; i < v; i++) {
    int p1 = dsum.find_set(i);
    int p2 = dsdois.find_set(i);
    remap[{p1, p2}].eb(i);
  }

  for (auto &[_, xs] : remap) {
    int xii = *xs.begin();
    for (auto xi : xs) dstres.union_set(xi, xii);
  }

  for (int i = 0; i < v; i++) {
    cout << dstres.size[dstres.find_set(i)] << " \n"[i == v - 1];
  }
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, graphs, dsu, connected components
