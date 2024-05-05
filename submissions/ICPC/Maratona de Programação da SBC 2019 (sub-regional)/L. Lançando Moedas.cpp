#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll N;
	cin >> N;

	ll bts = bitset<64>(N).count();

	ll ans = (1ll<<bts);

	cout << ans << '\n';
}

// AC, combinatorics
