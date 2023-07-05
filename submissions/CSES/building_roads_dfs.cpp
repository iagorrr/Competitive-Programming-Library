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

void dfs(int x, const vector<vll> &adj, vector<char> &vis) {
	vis[x] = true;
	for(auto v : adj[x]){
		if(!vis[v])
			dfs(v, adj, vis);
	}
}
void run() {
	ll v, e; cin >> v >> e;
	vector<vll> adj(v);
	for(int i = 0; i < e; ++i) {
		ll u, w; cin >> u >> w; u--; w--;
		adj[u].push_back(w);
		adj[w].push_back(u);
	}

	vector<pll> ans;
	vector<char> vis(v);
	ll prev = 0;
	dfs(0, adj, vis);
	for(ll i = 1; i < v; ++i) {
		if(!vis[i]) {
			ans.emplace_back(prev, i);
			prev = i;
			dfs(i, adj, vis);
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

// AC, graph, connected components
