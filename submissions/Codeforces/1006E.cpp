#include <bits/stdc++.h>
using namespace std;

const int maxn = 2'00'000;
vector<int> adj[maxn];

vector<int> order;
int pos[maxn];
int last[maxn];
void dfs(int u) {
	pos[u] = order.size();
	order.push_back(u);

	for (auto v : adj[u])
		dfs(v);
	last[u] = (int)order.size() - 1;
}

auto run() {
	int n, q;
	cin >> n >> q;

	for (int i = 1, p; i < n; i++) {
		cin >> p;
		p--;
		adj[p].emplace_back(i);
	}

	for (int i = 0; i < n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	dfs(0);

	while(q--) {
		int u, k;
		cin >> u >> k;
		u--;

		int p2 = pos[u] + k-1;
		cout << (p2 <= last[u] ? order[p2] +1: -1) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	// cin >> t;
	while(t--)
		run();
}

// AC, trees
