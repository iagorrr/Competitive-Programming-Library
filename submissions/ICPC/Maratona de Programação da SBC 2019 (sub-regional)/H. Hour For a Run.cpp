#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll v, n;
	cin >> v >> n;

	ll t = v * n*100;
	ll ten = t/10;
	for (int i = 1; i <= 9; i++) {
		ll c = ten * i;
		ll d = c%10 + (c/10)%10;
		c /= 100;
		if (d) c++;

		cout << c  << " \n"[i==9];
	}
}


// AC, ad-hoc
