#include <bits/stdc++.h>
using namespace std;


auto run() {
	int n;
	cin >> n;

	vector<int> xs(n);
	for (auto &xi : xs) cin >> xi;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int m = xs[i];
		int s = 0;
		for (int j = i; j < n; j++) {
			m = min(xs[j], m);
			int cur = (j-i+1)*m;
			// cerr << i << ' ' << j << ' ' << m <<  cur << '\n';
			ans = max(ans, cur);
		}
	}

	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	run();
}

// AC, greddy
