#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> xs;

const int maxn = 40;
set<ll> all(vector<ll> &xs, int k) {
	set<ll> ret;

	for (int m = 0; m < (1ll<<k); m++) {
		ll s = 0;
		bitset<maxn> mask(m);
		for (int i = 0; i < k; i++) {
			if (mask[i])
				s += xs[i];
		}
		ret.emplace(s);
	}

	return ret;
}

auto run() {
	int n;
	cin >> n;

	ll t;
	cin >> t;

	xs.resize(n);
	for (auto &xi : xs)
		cin >> xi;


	auto s1 = all(xs, n/2);
	reverse(xs.begin(), xs.end());
	auto tmp  = all(xs, (n+1)/2);
	auto s2 = vector<ll>(tmp.begin(), tmp.end());


	ll ans = 0;
	for (auto i : s1)  {
		for (int l = 0, r = (int)s2.size() - 1; l <= r;) {
			int m = (l + r) / 2;
			if (s2[m] + i <= t) {
				ans = max(ans, i + s2[m]);
				l = m + 1;

			}
			else r = m - 1;
		}
	}

	cout << ans << '\n';

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}

// AC, buteforce, meet in the middle, binary search
