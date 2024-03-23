#include <bits/stdc++.h>
using namespace std;

const int maxn = 1'00'000;
vector<int> adj[maxn];
int sz[maxn];
int n, k;
void reset() {
	for (int i = 0; i < n; i++) {
		adj[i] = {};
		sz[i] = 0;
	}
}

int maxcuts(int u, int p, int minlen, int &n) {
	int ret = 0;
	sz[u] = 1;
	for (auto v : adj[u]) if (v != p) {
		ret += maxcuts(v, u, minlen, n);
		if (sz[v] >= minlen and (n-sz[v]) >= minlen) {
			n -= sz[v];
			ret++;
		}
		else sz[u] += sz[v];
	}

	return ret;
}

void solve() {
	cin >> n >> k;
	reset();
	for (int i = 0, a, b; i < n-1; i++) {
		cin >> a >> b;
		a--, b--;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}

	int ans = 0;
	for (int l = 0, r = n; l <= r; ) {
		int mid = (l+r)/2;
		int tn = n;
		int m = maxcuts(0, -1, mid, tn);
		if (m >= k) {
			ans = max(ans, mid);
			l = mid + 1;
		}
		else r = mid - 1;
	}

	cout << ans << '\n';
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

// AC, greddy, binary search
