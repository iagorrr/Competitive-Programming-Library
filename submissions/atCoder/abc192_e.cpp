#include <bits/stdc++.h>
using namespace std;

using ll = long long;


const ll oo = 1e16;

const int maxn = 1'00'000;

using t3 = tuple<ll,ll,ll>;

int n, m, x, y;
vector<t3> adj[maxn];

vector<ll> dijkstra(int s) {
	priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<>> pq;
	vector<ll> ds(n, oo);
	ds[s] = 0;
	pq.emplace(0, s);

	while (!pq.empty()) {
		auto [du, u] = pq.top();
		pq.pop();
		if (ds[u] < du) continue;

		for (auto [v, k, t] : adj[u]) {
			ll t2 = du + t;
			t2 += ((du % k) ? k - (du%k) : 0);
			if (t2 < ds[v]) {
				ds[v] = t2;
				pq.emplace(t2, v);
			}
		}
	}

	return ds;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> x >> y;
	x--, y--;

	for (int i = 0; i < m; i++) {
		int a, b, k, t;
		cin >> a >> b >> t >> k;
		a--, b--;
		adj[a].emplace_back(b, k ,t);
		adj[b].emplace_back(a, k ,t);
	}

	auto ds = dijkstra(x);

	cout << (ds[y] == oo ? -1 : ds[y]) << '\n';
}

// AC, graphs, dijkstra, math
