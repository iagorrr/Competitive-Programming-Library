#include <bits/stdc++.h>
using namespace std;

bool solve() {
	int n;
	cin >> n;

	vector<int> xs(n);
	for (auto &xi : xs) cin >> xi;

	int l = 1, r = n-2;
	while (l <= r) {
		if (xs[l] < 0 or xs[r] < 0) return false;
		if (xs[l-1] < 0 or xs[r+1] < 0) return false;

		int a = xs[l-1];
		xs[l-1] = 0;
		xs[l] -= a *2;
		xs[l+1] -= a;

		int b = xs[r+1];
		xs[r+1] = 0;
		xs[r] -= b * 2;
		xs[r-1] -= b;


		l++, r--;

		if (xs[l] < 0 or xs[r] < 0) return false;
		if (xs[l-1] < 0 or xs[r+1] < 0) return false;
	}
	return *max_element(xs.begin(), xs.end()) == 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cout << (solve() ? "YES" : "NO") << '\n';
	}
}

// AC, greddy
