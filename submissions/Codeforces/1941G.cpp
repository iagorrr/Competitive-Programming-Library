#include <bits/stdc++.h>
using namespace std;


void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int,int>>> adj(n);
	for (int i = 0, u, v, c; i < m; i++) {
		cin >> u >> v >> c;
		u--, v--;
		adj[u].emplace_back(v, c);
		adj[v].emplace_back(u, c);
	}

	int s, e;
	cin >> s >> e;
	s--, e--;

	if (s == e)  {
		cout << 0 << '\n';
		return;
	}

	map<pair<int,int>, int> dist;
	priority_queue<tuple<int,int,int>
		, vector<tuple<int,int,int>>, greater<>> pq;
	dist[{s, -1}] = 0;
	pq.emplace(0, s, -1);

	while (!pq.empty()) {
		auto [du, u, cu] = pq.top();
		pq.pop();

		if (dist[{u, cu}] < du) continue;;

		for (auto [v, cv] : adj[u]) {
			if (dist.count({v, cv})) {
				if (dist[{v,cv}] <= du + (cu != cv))
					continue;

				dist[{v, cv}] = dist[{u, cu}] + (cu != cv);
				pq.emplace(dist[{v,cv}], v, cv);
			}
			else {
				dist[{v, cv}] = dist[{u, cu}] + (cu != cv);
				pq.emplace(dist[{v,cv}], v, cv);
			}
		}
	}

	int ans = 1e9;
	for (auto [_, ce] : adj[e]) {
		if (dist.count({e, ce}))
			ans = min(ans, dist[{e, ce}]);
	}
	
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}

// AC, dijkstra
