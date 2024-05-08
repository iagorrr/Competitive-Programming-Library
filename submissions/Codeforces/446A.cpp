#include <bits/stdc++.h>
using namespace std;

auto run() {
	int n;	
	cin >> n;

	vector<int> xs(n);
	for (auto &xi :xs) cin >> xi;

	vector<int> szs(n, -1), sze(n, -1);
	
	for (int i = 0; i < n;) {
		int j = i + 1;
		for (j = i+1; j < n and xs[j-1] < xs[j]; j++) {
		}

		int ni = j;
		int sz = j -i;
		int sz2 = 1;
		for (int k = 0; k < j-i; k++) {
			szs[i+k] = max(szs[i+k], sz);
			sze[i+k] = max(sze[i+k], sz2);
			sz2++;
			sz--;
		}

		i = ni;
	}

	int ans = 1;
	for (int i = 0; i < n; i++) {
		ans = max({ans, szs[i], sze[i]});
		if (i) {
			ans = max(ans, sze[i-1]+1);
		}
		if (i+1 < n) {
			ans = max(ans, szs[i+1]+1);
		}

		if (i and i +1 < n and xs[i-1] + 1 < xs[i+1]) {
			ans = max(ans, sze[i-1] + 1 + szs[i+1]);
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

// AC, brute force, dp
