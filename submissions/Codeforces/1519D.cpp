#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxn(5000);
ll as[maxn], bs[maxn], prods[maxn], psum[maxn];
ll dp[maxn+1][maxn+1];


ll solve(int i, int j) {
	if (i > j) return 0;
	if (i == j) return as[i] * bs[j];
	auto &ans = dp[i][j];

	if (ans != -1) return ans;
	return ans = as[i] * bs[j] + as[j] * bs[i] + solve(i+1, j-1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(dp, -1, sizeof dp);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> as[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> bs[i];
	}

	for (int i = 1; i <= n; i++) {
		psum[i] = psum[i-1] + as[i-1] * bs[i-1];
	}


	ll ans = psum[n];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ll left = psum[i];
			ll mid = solve(i, j);
			ll right = (psum[n] - psum[j+1]);
			ans = max(ans, left + mid + right);
		}
	}

	cout << ans << '\n';
}

// AC, dynamic programming, prefix sum
