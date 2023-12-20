#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vi2d = vector<vi>;
#define len(x) (int)x.size()
#define all(x) x.begin(), x.end()



map<vi, int> hasher;
int hs = 0;
struct RootedTreeIso {
	int n;
	vi2d adj;
	vi hashes;
	RootedTreeIso(int _n):n(_n), adj(_n), hashes(_n, -1) {};
	
	void add_edge(int u, int v) {
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}

	int hash(int u, int p = -1) {
		if (hashes[u] != -1) return hashes[u];

		vi children;
		for (auto v : adj[u])
			if (v != p)
			children.emplace_back(hash(v, u));

		sort(all(children));
		if (!hasher.count(children))
			hasher[children] = hs++;
		
		return hashes[u] = hasher[children];

	}
};

void solve() {
	int N;
	cin >> N;

	RootedTreeIso t1(N), t2(N);

	for (int i = 0; i < N-1; i++)  {
		int u, v;
		cin >> u >> v;
		u--, v--;
		t1.add_edge(u, v);
	}


	for (int i = 0; i < N-1; i++)  {
		int u, v;
		cin >> u >> v;
		u--, v--;
		t2.add_edge(u, v);
	}


	if (t1.hash(0) == t2.hash(0)) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}


// AC, trees, graphs, isomorphism
