#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> as(n), bs(m);
	for (auto &ai : as) cin >> ai;
	for (auto &bi : bs) cin >> bi;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans += (as[i] + bs[j] <= k);
		}
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


// AC, implementation

