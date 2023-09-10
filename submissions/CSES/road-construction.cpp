#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int)__x.size()
using ll = long long;
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

struct DSU {
  vi ps;
  vi size;
  int components;
  int larger;
  DSU(int N) : ps(N + 1), size(N + 1, 1), components(N), larger(1) {
    iota(all(ps), 0);
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
    larger = max(larger, size[px]);
    components--;
  }
};

void run() {
  int n, m;
  cin >> n >> m;

  DSU dsu(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    dsu.union_set(a, b);
    cout << dsu.components << ' ' << dsu.larger << endl;
  }
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, dsu
