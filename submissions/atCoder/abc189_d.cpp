#include <bits/stdc++.h>
using namespace std;

vector<string> xs;
using ll = long long;


ll memo[66][2][2];

ll solve(int i, bool v, bool c) {
	if (i == 0) {
		return v == c;
	}

	auto &ans = memo[i][v][c];
	if (ans != -1) return ans;

	ans = 0;

	if (xs[i-1] == "AND") {
		if (v) {
			if (c) {
				ans += solve(i-1, 1, 0);
				ans += solve(i-1, 1, 1);
			}
		}
		else {
			if (!c) {
				ans += solve(i-1, 0, 0);
				ans += solve(i-1, 0, 1);

				ans += solve(i-1, 1, 0);
				ans += solve(i-1, 1, 1);
			}
			else {
				ans += solve(i-1, 0, 0);
				ans += solve(i-1, 0, 1);
			}
		}
	}
	else {
		if (v) {
			if (c) {
				ans += solve(i-1, 0, 0);
				ans += solve(i-1, 0, 1);

				ans += solve(i-1, 1, 0);
				ans += solve(i-1, 1, 1);
			}
			else {

				ans += solve(i-1, 1, 0);
				ans += solve(i-1, 1, 1);
			}
		}
		else {
			if (!c) {
				ans += solve(i-1, 0, 0);
				ans += solve(i-1, 0, 1);
			}
		}
	}

	return ans;
}


auto run() {
	memset(memo, -1, sizeof memo);

	int n;
	cin >> n;
	xs.resize(n);

	for (auto &xi : xs) cin >> xi;

	cout << solve(n, 1, 0) + solve(n, 1, 1) << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	run();
}


// AC, DP
