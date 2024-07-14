#include <bits/stdc++.h>
using namespace std;

#include "../../../../algorithms/math/gauss-xor.cpp"

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, f;
	cin >> n >> f;

	vector<vector<int>> adj(n);
	while (f--) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	GaussXor gauss;
	for (int i = 0; i < n; i++) {
		Equation eq;

		for (auto v : adj[i]) {
			eq.set(v);
		}

		if (adj[i].size() & 1) {
			eq.set(i);
			gauss.add(eq, 0);
		}
		else {
			gauss.add(eq, 1);
		}
	}

	cout << "NY\n"[gauss.solution().first] << '\n';
}

