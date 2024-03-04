#include <bits/stdc++.h>
using namespace std;


const int maxn(1'00'000);
int n;
vector<pair<int, long long>> adj[maxn];

int color[maxn];
void dfs(int u, long long ds = 0) {
	color[u] = ds & 1;

	for (auto [v, d] : adj[u]) {
		if (color[v] != -1) continue;
		long long ds2 = color[u] ? ds + d : d;
		dfs(v, ds2);
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(color, -1, sizeof color);

	cin >> n;

	for (int i = 0, a, b, c; i < n-1; i++) {
		cin >> a >> b >> c;
		a--, b--;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}

	dfs(0);

	for (int i = 0; i < n; i++) {
		cout << color[i] << '\n';
	}
}

// AC, bfs/dfs
