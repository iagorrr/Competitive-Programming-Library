#include <bits/stdc++.h>
using namespace std;

using ll = long long;
auto run() {
	ll l, r;

	cin >> l >> r;

	vector<pair<ll,ll>> ans;

	while (l != r) {
		ll p2 = 1;
		while ((l % (p2*2ll)) == 0 and l + (p2*2ll) <= r) {
			p2 *= 2ll;
		}
		ans.emplace_back(l, l + p2);
		l = l + p2;
	}

	cout << ans.size() << '\n';
	for (auto [a, b] : ans) {
		cout << a << ' ' << b << '\n';
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}
