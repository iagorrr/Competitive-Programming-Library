// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define rep(i, l, r) for (int i = (l); i < (r); i++)
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(xxxx)                                                              \
  for (auto &xxx : xxxx)                                                       \
    cin >> xxx;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first

void dbg_out() { cerr << endl; }
template <typename H, typename... T> void dbg_out(H h, T... t) {
  cerr << ' ' << h;
  dbg_out(t...);
}
#define dbg(...)                                                               \
  {                                                                            \
    cerr << #__VA_ARGS__ << ':';                                               \
    dbg_out(__VA_ARGS__);                                                      \
  }

struct DSU {
  vector<int> ps;
  vector<int> size;
  DSU(int N) : ps(N + 1), size(N + 1, 1) { iota(ps.begin(), ps.end(), 0); }
  int find_set(int x) { return ps[x] == x ? x : ps[x] = find_set(ps[x]); }
  bool same_set(int x, int y) { return find_set(x) == find_set(y); }
  void union_set(int x, int y) {
    if (same_set(x, y))
      return;

    int px = find_set(x);
    int py = find_set(y);

    if (size[px] < size[py])
      swap(px, py);

    ps[py] = px;
    size[px] += size[py];
  }
};

void run() {
	ll v, e; cin >> v >> e;
	DSU dsu(v);	
	for(int i = 0; i < e; ++i) {
		ll u, w; cin >> u >> w; u--; w--;
		dsu.union_set(u, w);
	}

	vector<char> vis(v);
	vector<pll> ans;
	ll father = dsu.find_set(0);
	vis[father] = true;
	for(ll i = 0; i < v; ++i) {
		ll fset = dsu.find_set(i);
		if(!vis[fset]) {
			ans.emplace_back(father, fset);
			vis[fset] = true;
		}
	}

	cout << ans.size() << '\n';
	for(auto [a, b] : ans) {
		cout << a+1 << ' ' << b+1 << '\n';
	}
}

int32_t main(void) {
  	fastio;
	int t;
	t = 1;
	while (t--)
		run();
}

// AC, graph, connected components, dsu

