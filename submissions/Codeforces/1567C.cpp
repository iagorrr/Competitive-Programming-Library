#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve(int n) {
	string sn = to_string(n);
	reverse(sn.begin(), sn.end());

	// cerr << "sn: " << sn << '\n';

	ll a = 0, b = 0;
	for (ll i = 0, p10 = 1; i < (int)sn.size(); i+= 2, p10 *= 10) {
		a += (sn[i]-'0')*p10;
		if (i + 1 < (int)sn.size())
			b += (sn[i+1]-'0')*p10;
	}

	// cerr << "a: " << a << " b: " << b << '\n';
	return (a+1ll) * (b+1ll) - 2ll;
}

auto run() {
	int n;
	cin >> n;
	cout << solve(n) << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--) {
		run();
	}
}

// AC, math, combinatorics
