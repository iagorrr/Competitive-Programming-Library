#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	ll s = 0, r =0;
	vector<ll> all(n);

	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		r += x;

	}


	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		all[i] = x;
	}

	sort(all.begin(), all.end());

	ll m = all[n-1] + all[n-2];

	if (m >= r) {
			cout << "YES\n";
	}
	else {
			cout << "NO\n";

	}
	return 0;
}

// AC, ad-hoc
