#include <bits/stdc++.h>
using namespace std;

auto run() {
	int n;
	cin >> n;

	vector<int> xs(n);
	for (auto &xi : xs) cin >> xi;

	sort(xs.begin(), xs.end());
	int ans = n;

	int n2 = n / 2;
	for (int i = 0; i < n / 2; i++) {
		for ( ; n2 < n; n2++) {
			if (xs[i]* 2 <= xs[n2]) {
				ans--;
				n2++;
				break;
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	// cin >> t;
	while(t--)
		run();
}

// AC, greddy
