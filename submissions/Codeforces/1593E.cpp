#include <bits/stdc++.h>
using namespace std;

/*
	A cada movimento vai ser o 
	quem tiver aquele grau no toposort
 */
const int maxn = 4 * 1'00'000;
vector<int> adj[maxn];

int n, k;

int tin[maxn];
int permove[maxn];
int dg[maxn];

int solve() {
	for (int i = 0; i < n; i++) {
		permove[i] = 0;
	}

	queue<int> q;

	for (int i = 0; i < n; i++) {
		dg[i] = adj[i].size();
		if (dg[i] == 1) {
			tin[i] = 1;
			q.emplace(i);
			permove[1]++;
		}
	}

	while (q.size()) {
		auto u = q.front();
		q.pop();

		for (auto v : adj[u]) {
			dg[v]--;

			if (dg[v] == 1) {
				tin[v] = tin[u]+1;
				permove[tin[v]]++;
				q.emplace(v);
			}
		}

	}

	int ans = n;
	for (int i = 1; i <= k; i++) {
		ans -= permove[i];
	}

	return max(ans, 0);
}

auto run() {
	cin >> n >> k;

	for (int i =0 ; i < n; i++) {
		adj[i].clear();
	}	

	for (int i = 0, a, b; i < n - 1; i++) {
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	if (n <= 2) {
		cout << !(k) << '\n';
		return;
	}
	cout << solve() << '\n';

}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;

	while (t--) {
		run();
	}

}

// AC, trees, dfs and similar
