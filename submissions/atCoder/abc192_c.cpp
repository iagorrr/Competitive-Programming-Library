#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int long long
ll g1(ll x) {
	string xs = to_string(x);
	sort(xs.begin(), xs.end());
	ll ret = 0;
	for (int i = (int)xs.size()-1, p10 = 1; i >= 0; i--, p10 *= 10) {
		ret += p10 * (xs[i] - '0');
	}
	return ret;
}

ll g2(ll x) {
	string xs = to_string(x);
	sort(xs.rbegin(), xs.rend());
	ll ret = 0;
	for (int i = (int)xs.size()-1, p10 = 1; i >= 0; i--, p10 *= 10) {
		ret += p10 * (xs[i] - '0');
	}
	return ret;
}

ll f(ll x) {
	return g2(x) - g1(x);
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll sn, sk;
	cin >> sn >> sk;

	ll prev = sn;
	for (int i = 0; i < sk; i++) {
		ll cur = f(prev);
		prev = cur;
	}

	cout << prev << '\n';
}

// AC, math, implementation
