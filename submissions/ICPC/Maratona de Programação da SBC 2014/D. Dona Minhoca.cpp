#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const int maxn(10000);
int N, T, Q;
ll oo = 1'000'000'000'000'000'000;
vector<vector<pair<ll,int>>> G;


ll dists[maxn];
ll ans;
void dijkstra(int s) {
	for (int i = 0; i < N; i++) {
		dists[i] = oo;
	}
	dists[s] = 0;

	priority_queue<pll, vector<pll>, greater<pll>> pq;
	pq.emplace(0, s);
	
	while (not pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		if (dists[u] < d) continue;

		for (auto [dv, v] : G[u]) {
			ll d2 = dv + d;
			if (d2 >= dists[v]) continue;
			dists[v] = d2;
			pq.emplace(d2, v);
		}
	}
}

ll dfsdis[maxn];
void dfs(int u, ll m, ll curdist, int prev) {
	if (dfsdis[u] != -1) {
		ll csize = curdist - dfsdis[u];
		if (csize >= m) {
			ll curans = dists[u]*2ll + csize;	
			ans = min(ans, curans);
		}
		return;
	}

	dfsdis[u] = curdist;

	for (auto [dv, v] : G[u]) {
		if (prev == v) continue;
		dfs(v, m, curdist+dv, u);
	}
}

void solve(int source, ll m) {
	dijkstra(source);
	ans = oo;

	memset(dfsdis, -1, sizeof dfsdis);
	dfs(source, m, 0, -1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> T;
	G.resize(N);

	for (int i = 0; i < T; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		a--, b--;
		G[a].emplace_back(c, b);
		G[b].emplace_back(c, a);
	}

	cin >> Q;
	while(Q--) {
		int u;
		ll m;
		cin >> u >> m;
		u--;
		solve(u, m);
		ans = ans == oo ? -1 : ans;
		cout << ans << endl;
	}
}

/*
 * AC
 * Graphs
 * Dijkstra
 * BFS/DFS
 * Cycles
 * */
