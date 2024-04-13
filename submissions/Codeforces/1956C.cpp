#include <bits/stdc++.h>
using namespace std;



using ll = long long;
auto solve(int n) {
	ll s = 0;
	for (ll k = 1; k <= n; k++) {
		s += k * k * 2 - k;
	}

	cout << s << ' ' << 2*n << '\n';

	int c = 1;
	for (int i = 1; i <= 2*n; i++) {
		cout << (2 - (i&1)) << ' ' << c;
		for (int j = n; j >= 1; j--) cout << ' ' << j;
		cout << '\n';
		c += !(i&1);
	}
}


auto run() {
	int n; 
	cin >> n;


	solve(n);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	for (int i = 1; i <= tt; i++) {
		run();
	}
}

// AC, greddy, constructive algorithms
