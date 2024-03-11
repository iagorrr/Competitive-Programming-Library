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


	const int oo = n + 1;
	vector<int> dist(n, oo);
	dist[s] = 0;

	deque<pair<int,int>> dq;
	dq.emplace_front(s, -1);

	while(!dq.empty()) {
		auto [u, cu] = dq.front();
		cerr << u << ' ' << cu << ' ' << dist[u] << '\n';
		dq.pop_front();

		for (auto [v, cv] : adj[u]) {
			if (dist[v] <= dist[u] + (cv != cu)) continue;
			dist[v] = dist[u] + (cv != cu);
			if (cv == cu) {
				dq.emplace_front(v, cv);
			}
			else {
				dq.emplace_back(v, cv);
			}
		}
	}

	cout << dist[e] << '\n';
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
