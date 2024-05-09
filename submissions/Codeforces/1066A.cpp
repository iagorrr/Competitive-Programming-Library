#include <bits/stdc++.h>
using namespace std;

using ll = long long;
auto run() {
	ll s, v, l, r;
	cin >> s >> v >> l >> r;

	ll ans = s / v;

	ll m0 = (l / v) * v;
	ll m1;
	if (m0 == l) {
		m1 = m0;
	}
	else {
		m1 = m0 + v;
	}

	ll m2 = (r  / v * v);

	ll k1 = m1 / v;
	ll k2 = m2 / v;
	ll decre = k2 - k1 + 1;
	ans -= decre;

	cout << ans << '\n';

}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;

	while (tt--) {
		run();
	}
}

// AC, math
