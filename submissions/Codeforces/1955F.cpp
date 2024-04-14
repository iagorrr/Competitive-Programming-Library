#include <bits/stdc++.h>
using namespace std;


const int maxpi = 200;
int dp[maxpi + 2][maxpi + 2][maxpi + 2];

void precalc() {
	for (int i = 0; i <= maxpi; i++) {
		for (int j = 0; j <= maxpi; j++) {
			for (int k = 0; k <= maxpi; k++) {
				int one = 1 * (i & 1);
				int two = 2 * (j & 1);
				int three = 3 * (k & 1);
				dp[i][j][k] += !(one^two^three);
				int cur = dp[i][j][k];
				dp[i+1][j][k] = max(dp[i+1][j][k], cur);
				dp[i][j+1][k] = max(dp[i][j+1][k], cur);
				dp[i][j][k+1] = max(dp[i][j][k+1], cur);
			}
		}
	}
}

auto run() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	cout << d/2 + dp[a][b][c] - 1 << '\n';
}

int32_t main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;

	precalc();
	for (int i = 1; i <= tt; i++) {
		run();
	}
}

// AC, dp, games
