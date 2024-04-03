#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1'000'000'000 + 7;

ll n, m, t;
const int maxt = 50;
const int maxn = 1'00'000;
vector<vector<ll>> memo(maxt+1, vector<ll>(maxn+1));

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t >> m >> n;

	for (int i = m; i <= n; i++) {
		memo[1][i] = 1;
	}

	for (int i = 2; i <= t; i++) {
		for (int j = m; j <= n; j++) {
			memo[i][j] = (memo[i-1][j-1] + memo[i-1][j+1]) % mod;
		}
	}


	ll ans =  0;
	for (int i = m; i <= n; i++) {
		ans = (ans + memo[t][i]) % mod;
	}


	cout << ans << '\n';
}

// AC, dp
