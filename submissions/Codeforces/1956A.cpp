#include <bits/stdc++.h>
using namespace std;


auto run() {
	int k, q;
	cin >> k >> q;

	vector<int> xs(k+1);
	for (int i = 1; i <= k; i++) cin >> xs[i];

	while (q--) {
		int n;
		cin >> n;
		while (1) {
			int sub = 0;
			for (int l = 0, r = k; l <= r; ) {
				int m = (l+r)/2;
				if (xs[m] <= n) {
					l = m + 1;
					sub = max(sub, m);
				}
				else r = m - 1;
			}
			if (sub == 0) break;
			n -= sub;

		}
		cout << n << ' ';

	}
	cout << '\n';
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

// AC, greddy
