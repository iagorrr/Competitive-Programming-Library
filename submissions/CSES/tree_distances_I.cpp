// iagorrr ;)
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)


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

pll mostDistantFrom(const vector<vll> &adj, ll n, ll root) {
  // 0 indexed
  ll mostDistantNode = root;
  ll nodeDistance = 0;
  queue<pll> q;
  vector<char> vis(n);
  q.emplace(root, 0);
  vis[root] = true;
  while (!q.empty()) {
    auto [node, dist] = q.front();
    q.pop();
    if (dist > nodeDistance) {
      nodeDistance = dist;
      mostDistantNode = node;
    }
    for (auto u : adj[node]) {
      if (!vis[u]) {
        vis[u] = true;
        q.emplace(u, dist + 1);
      }
    }
  }
  return {mostDistantNode, nodeDistance};
}
ll twoNodesDist(const vector<vll> &adj, ll n, ll a, ll b) {
  // 0 indexed
  queue<pll> q;
  vector<char> vis(n);
  q.emplace(a, 0);
  while (!q.empty()) {
    auto [node, dist] = q.front();
    q.pop();
    if (node == b) {
      return dist;
    }
    for (auto u : adj[node]) {
      if (!vis[u]) {
        vis[u] = true;
        q.emplace(u, dist + 1);
      }
    }
  }
  return -1;
}
tuple<ll,ll,ll> tree_diameter(const vector<vll> &adj, ll n) {
  // 0 indexed !!!
  auto [node1, dist1] = mostDistantFrom(adj, n, 0);
  auto [node2, dist2] = mostDistantFrom(adj, n, node1);
  auto diameter = twoNodesDist(adj, n, node1, node2);
  return make_tuple(node1, node2, diameter);
}

vll everyDistanceFromNode(const vector<vll> &adj, ll n, ll node){
	queue<pair<ll,ll>> q;
	vll ans(n, -1);
	ans[node] = 0;
	q.emplace(node, 0);
	while(!q.empty()){

		auto [u, d] = q.front(); q.pop();

		for(auto w : adj[u]){
			if(ans[w] != -1) continue;
			ans[w] = d + 1;
			q.emplace(w, d+1);
		}
	}
	return ans;
}

void run() {
	ll v; cin >> v;
	vector<vll> adj(v);
	for(int i = 0; i < v-1; ++i) {
		ll a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	auto [node1, node2, diameter] = tree_diameter(adj, v);
	auto distances1 = everyDistanceFromNode(adj, v, node1);
	auto distances2 = everyDistanceFromNode(adj, v, node2);
	for(int i = 0;  i < v; ++i) {
		auto ans = max(distances1[i], distances2[i]);
		cout << ans << ' ';
	}
	cout << '\n';
}

int32_t main(void) {
  	// fastio;
	int t;
	t = 1;
	while (t--)
		run();
}

// AC, tree, diameter
