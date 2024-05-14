#include <bits/stdc++.h>
using namespace std;

using ll = long long;
vector<ll> fats;
void precomp(){ 
	ll f = 1;
	for (ll i = 1; f <= 1'00'000; i++) {
		fats.push_back(f);
		f *= i;
	}
}

auto solve() {
	precomp();
	ll n;
	cin >> n;

	ll ans = 0;
	while (n) {
		while (fats.back() > n) fats.pop_back();
		n -= fats.back();
		ans++;
	}
	cout << ans << '\n';

}


int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}
