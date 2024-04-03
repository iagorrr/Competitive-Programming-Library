#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1'0'000;
int n, c;
ll money[maxn];
ll ans = 0;
vector<pair<int,ll>> adj[maxn];

void dfs(int u, int p, ll pw) {
	for (auto [v, w] : adj[u]) {
		if (v == p) continue;
		ans += w; // ir
		dfs(v, u, w);
	}

	if (p == -1) return;

	ll vai = (money[u] / c) + ((money[u] % c) != 0);
	vai--;
	ans += pw;
	ans += vai*2 * pw;
	money[p] += money[u];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> money[i];
	}

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		a--, b--;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}

	dfs(0, -1, 0);

	cout << ans << '\n';
}

// AC, greddy, graphs, dfs
