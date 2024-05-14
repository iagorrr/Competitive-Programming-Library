#include <bits/stdc++.h>
using namespace std;

auto solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	vector<vector<long long>> dp(2, vector<long long>(1001, -INT_MAX));
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		dp[1] = dp[0];
		for (int j = 1; j <= 1000; j++) {
			dp[1][0] = max(dp[1][0], dp[0][j] + a[i] - m);
		}
		dp[1][a[i]] = dp[0][0] - a[i];
		swap(dp[0], dp[1]);
	}
	cout << *max_element(dp[0].begin(), dp[0].end()) << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}

// AC, dynamic programming
