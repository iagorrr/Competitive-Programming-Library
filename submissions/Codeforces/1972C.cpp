#include <bits/stdc++.h>
using namespace std;

using ll = long long;

pair<ll,ll> getx(vector<ll> &as, ll k) {
	ll x = *min_element(as.begin(), as.end());
	ll cost = 0;

	auto get_cost = [&](ll m) -> ll {
		ll ret = 0;
		for (auto &ai : as)
			ret += max(0ll, m-ai);
		return ret;
	};

	for (ll l = 0, r = 1e13; l <= r; ) {
		ll m = midpoint(l, r);
		ll c = get_cost(m);
		if (c <= k) {
			x = max(x, m);
			cost = c;
			l = m + 1;
		}
		else r = m - 1;
	}

	return {x, cost};
}

auto run() {
	ll n, k;
	cin >> n >> k;

	vector<ll> as(n);
	for (auto &ai : as) cin >> ai;

	auto [x, c] = getx(as, k);	
	ll m = 0;
	for (auto &ai : as) m += ai <= x;
	ll r = k - c;
	m -= r;
	// cerr << x << ' ' << n << ' ' << m << '\n';
	ll ans = x * n + 1 - m;
	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;

	while (tt--)
		run();
}

// AC, constructive, greddy, binary search
