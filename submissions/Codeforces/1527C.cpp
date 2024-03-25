#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> xs(n);
	for (auto &xi : xs) cin >> xi;

	vector<long long> dp(n);
	map<int, long long> acc_pos;
	acc_pos[xs[0]] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = dp[i-1] + acc_pos[xs[i]];
		acc_pos[xs[i]] += i+1;
	}
	cout << accumulate(dp.begin(), dp.end(), 0ll) << '\n';
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

// AC, DP

