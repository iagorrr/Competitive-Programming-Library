#include <bits/stdc++.h>
using namespace std;



auto run() {
	int n;
	cin >> n;

	vector<int> xs(n);
	for (auto &xi : xs) cin >> xi;
	
	vector<int> ans(n);

	for (int l = 0, r = n-1; l < r; l++, r--) {
		ans[l] = xs[r];
		ans[r] = -xs[l];
	}

	if (n&1) {
		ans[n/2] = xs[n/2+1];
		ans[n/2+1] += -xs[n/2];

		if (ans[n/2+1] == 0) {
			ans[n/2] += xs[n/2+1];
			ans[n/2+1] += -xs[n/2];
		}
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " \n"[i==n-1];
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;

	while (tt--) {
		run();
	}

}

// AC, contructive algorithms, math
