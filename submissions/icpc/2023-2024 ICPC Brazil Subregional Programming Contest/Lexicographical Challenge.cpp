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

const ll INF = 1e18;

struct DSU {
  vector<int> ps;
  vector<int> size;
  vector<multiset<char>> elements;
  DSU(int N) : ps(N + 1), size(N + 1, 1), elements(N + 1) {
    iota(ps.begin(), ps.end(), 0);
  }

  DSU(string vs)
    : ps(len(vs) + 1), size(len(vs) + 1, 1), elements(len(vs) + 1) {
    iota(ps.begin(), ps.end(), 0);
    for (int i = 0; i < len(vs); i++) {
      elements[i].insert(vs[i]);
    }
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
    elements[px].insert(all(elements[py]));
  }
};
void run() {
  string s;
  cin >> s;
  int k;
  cin >> k;

  DSU dsu(s);
  int n = len(s);
  for (int i = 0; i < n; i++) {
    if (i + k < n) dsu.union_set(i, i + k);
    if (i - k >= 0) dsu.union_set(i, i - k);
  }

  string ans;
  for (int i = 0; i < n; i++) {
    char cur = *dsu.elements[dsu.find_set(i)].begin();
    ans += cur;

    dsu.elements[dsu.find_set(i)].erase(
      dsu.elements[dsu.find_set(i)].find(cur));
  }

  cout << ans << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, dsu, strings
