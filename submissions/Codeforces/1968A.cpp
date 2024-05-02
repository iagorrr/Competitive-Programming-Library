#include <bits/stdc++.h>
using namespace std;

auto run() {
	int x;
	cin >> x;
	int ans = 1;
	int ansy = gcd(x,1) + 1;
	for (int y = 1; y < x; y++) {
		if (gcd(x,y) + y > ans) {
			ans = gcd(x, y) + y;
			ansy = y;
		}
	}
	cout << ansy << '\n';

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

// AC, brute force
