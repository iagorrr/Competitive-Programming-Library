#include <bits/stdc++.h>
using namespace std;


using ll = long long;
const ll oo = 1'000'000'000ll * 1'000'000'000ll;

const int maxn = 100;

ll n, x;
ll xs[maxn];
ll ans = oo;

int t;
ll dp[100][101][100];
ll solve(int i, int j, int k) {
	if (j == 0) {
		return k ? -1 : 0;
	}

	if (i == -1) {
		return -1;
	}

	auto &st = dp[i][j][k];
	if (st != 0) return st;


	int modi = xs[i] % t;
	int modc = (t+k-modi) % t;

	ll t1 = solve(i-1, j-1, modc);
	ll t2 = solve(i-1, j, k);

	if (t1 != -1) t1 += xs[i];

	st = max(t1, t2);
	return st;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> x;


	for (int i = 0; i < n; i++) {
		cin >> xs[i];
	}

	for (int k = 1; k <= n; k++) { 
		memset(dp, 0, sizeof dp);
		t = k;
		ll s = solve(n-1, k, (x)%k);
		if (s != -1) {
			ll cur = (x-s)/k;
			ans = min(ans, cur);
		}
	}

	cout << ans << '\n';

}

/*
   	- seja t a quantidade de peças que vamos pegar, com t fixo :
	- dp[i][j][k] = maior soma considerando somente os i primeiros
			elementos, pegando exatamente j, e tal que
			essa soma seja congruente a k mod T
	- um cadin de aritmética modular e shablau

	AC, number theory
 */
