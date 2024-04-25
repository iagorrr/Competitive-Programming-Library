#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1'000'000'000 +  7;


const int maxm = 2'00'000;
ll memo[10][maxm+1];
ll ds[10][maxm+1][10];


ll solved(int d, int m) {
	if (m == 0) {
		return 1;
	}


	auto &ans = memo[d][m];
	if (ans != -1) return ans;

	solved(d, m-1);

	for (int i = 0; i <= 8; i++) {
		ds[d][m][i+1] = ds[d][m-1][i];
	}

	ds[d][m][0] = (ds[d][m][0] + ds[d][m-1][9]) % mod;
	ds[d][m][1] = (ds[d][m][1] + ds[d][m-1][9]) % mod;

	ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans = (ans + ds[d][m][i]) % mod;
	}

	return ans;
}

ll solve(int n, int m) {

	ll ans =  0;

	while (n) {
		ll incre = + solved(n%10, m);
		// cerr << n%10 << ' ' << m << ' ' << incre << '\n';
		ans = (ans + incre) % mod;
		n /= 10;
	}

	return ans;
}

auto run() {
	int n, m;
	cin >> n >> m;

	cout << solve(n, m) << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	memset(memo, -1, sizeof memo);
	for (int i = 0; i <= 9; i++) {
		ds[i][0][i] = 1;
	}

	int t;
	cin >> t;

	while (t--)
		run();
}

// AC,  DP
