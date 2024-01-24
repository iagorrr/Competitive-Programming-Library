#include <bits/stdc++.h>
using namespace std;

const int maxn(1'00'000);
vector<int> g[maxn];
vector<int> leafs;

void solve(int u = 0, int p = -1) {
	int cnt = 0;
	for(auto v : g[u]) if (v != p) {
		cnt++;
		solve(v, u);
	}

	if (!cnt || (p == -1 and cnt==1)) leafs.emplace_back(u);

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}

	solve();

	vector<pair<int,int>> ans;
	int m = leafs.size();
	for (int i = 0; i + m/2 < m; i++) {
		ans.emplace_back(leafs[i], leafs[i+m/2]);
	}

	cout << ans.size() << '\n';
	for (auto &[a, b] : ans) {
		cout << a + 1 << ' ' << b + 1 << '\n';
	}
}

