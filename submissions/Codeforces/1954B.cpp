#include <bits/stdc++.h>
using namespace std;


auto run() {
	int n;
	cin >> n;

	vector<int> xs(n);
	for (auto &xi : xs) cin >> xi;

	int min_e = *min_element(xs.begin(), xs.end());
	int max_e = *max_element(xs.begin(), xs.end());
	if (min_e == max_e) {
		cout << -1 << '\n';
		return;

	}

	vector<int> ys;
	ys.emplace_back(0);

	for (int i = 1; i <= n; i++) {
		if (xs[i-1] != xs.front())
			ys.emplace_back(i);
	}

	ys.emplace_back(n+1);

	int ans = n*2;
	for (int i = 0; i + 1 < ys.size(); i++) {
		ans = min(ans, ys[i+1]-ys[i]-1);
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

// AC, ad-hoc
