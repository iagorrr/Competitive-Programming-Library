#include <iostream>
#include <vector>
#include <bitset>

const int maxn(5'0'000);

std::vector<int> adj[maxn];
int ans[maxn];

int n, m;

std::bitset<maxn> st[maxn];

void solve(int u) {
	if (ans[u]) return;

	st[u][u] = 1;
	for (auto v : adj[u]) {
		solve(v);
		st[u] |= st[v];
	}


	ans[u] = (int)st[u].count();
}

int main() {	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	std::cin >> n >> m;
	for (int i = 0, u, v; i < m; i++) {
		std::cin >> u >> v;
		u--, v--;
		adj[u].emplace_back(v);
	}

	for (int i = 0 ; i < n; i++) {
		solve(i);
		std::cout << ans[i] << " \n"[i==n-1];
	}
}

// AC, dag, bitset
