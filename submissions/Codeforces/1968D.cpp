#include <bits/stdc++.h>
using namespace std;

using ll = long long;

auto run() {
	ll n, k;
	cin >> n >> k;
	ll ps1, ps2;
	cin >> ps1 >> ps2;

	ps1--;
	ps2--;

	vector<ll> ps(n);
	for (int i = 0; i < n; i++) {
		cin >> ps[i];
		ps[i]--;
	}

	vector<ll> as(n);
	for (auto &ai : as) cin >> ai;

	ll max1 = 0;
	ll until = 0;
	ll u = ps1;
	for (ll i = 1; i <= min(n, k); i++) {
		until += as[u];
		ll cur = until + (k-i)*as[u];
		u = ps[u];

		max1 = max(max1, cur);
	}

	ll max2 = 0;
	until = 0;
	u = ps2;
	for (ll i = 1; i <= min(n, k); i++) {
		until += as[u];
		ll cur = until + (k-i)*as[u];
		u = ps[u];

		max2 = max(max2, cur);
	}

	if (max1 > max2) {
		cout << "Bodya\n";
	}
	else if (max2 > max1) {
		cout << "Sasha\n";
	}
	else {
		cout << "Draw\n";
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	for (int ttt = 1; ttt <= tt; ttt++) {
		run();
	}
}

// AC, greddy
