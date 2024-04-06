#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	map<int,vector<int>> pts;
	for (int i = 0; i < n; i++) pts[i].clear();

	for (int i = 0, a, b; i < n; i++) {
		cin >> a >> b;
		pts[b].emplace_back(a);
	}

	for (auto &[_, v] : pts) {
		sort(v.begin(), v.end());
	}
	
	set <int> m;
	for (auto &[_, v] : pts) {
		for (int l = 0, r = (int)v.size() -1; l <= r; l++, r--) {
			m.emplace(v[l]+v[r]);
		}
	}
	
	if (m.size() == 1) {
		cout << "YES";
	}
	else cout << "NO";
	cout << '\n';
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

// AC, geometry
