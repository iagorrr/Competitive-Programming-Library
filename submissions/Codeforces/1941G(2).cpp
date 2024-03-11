#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	
	map<int, vector<int>> adj;
	for (int i = 0, u, v, c; i < m; i++) {
		cin >> u >> v >> c;
		u--, v--, c+=n;

		adj[u].emplace_back(c);
		adj[c].emplace_back(u);

		adj[v].emplace_back(c);
		adj[c].emplace_back(v);
	}

	int s, e;
	cin >> s >> e;
	s--, e--;

	map<int, int> dist;
	dist[s] = 0;

	queue<int> q;
	q.emplace(s);

	while (!q.empty()) {
		auto u = q.front();
		q.pop();

		for (int i : adj[u]) {
			if (dist.count(i))
				continue;
			dist[i] = dist[u] + 1;
			q.emplace(i);
		}
	}

	cout << dist[e] / 2 << '\n';
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--)  {
		solve();
	}

}


// AC, bfs
