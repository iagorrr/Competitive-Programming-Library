#include <bits/stdc++.h>
using namespace std;

auto run() {
	int n, t;
	cin >> n >> t;
	int k;
	cin >> k;

	int ans = n;
	for (int i = 0, l = 1, r = n; i < 20 and l <= r; i++) {
		int m = midpoint(l,r);
		cout << "? " << 1 << ' ' << m << endl;
		int s;
		cin>> s;

		int q0 = m - s;
		if (q0 >= k) {
			ans = min(ans, m);
			r = m -1;
		}
		else l = m + 1;
	}

	cout << "! " << ans << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;

	while (t--) {
		run();
	}

}


// AC, interactive, binary search
