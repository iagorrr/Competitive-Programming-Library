#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
	int n;
	cin >> n;
	vector<ll> xs(n);
	for (auto &xi : xs) cin >> xi;
	sort(xs.begin(), xs.end());
	int i = 0, j = n -1, k = 1, l = n-2;
	ll ans =   	abs(xs[i]-xs[j]) +
			abs(xs[j]-xs[k]) +
			abs(xs[k]-xs[l]) +
			abs(xs[l]-xs[i]) ;

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

// AC, sortings, greddy
