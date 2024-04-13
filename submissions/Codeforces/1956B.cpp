#include <bits/stdc++.h>
using namespace std;


auto run() {
	int n;
	cin >> n;

	map<int, int> xs;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		xs[x]++;
	}

	int ans = 0;
	for (auto [_, q] : xs) {
		ans += q == 2;
	}

	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	
	for (int i = 1; i <= tt; i++) {
		run();
	}
}

// AC, greddy, games
