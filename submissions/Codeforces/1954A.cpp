#include <bits/stdc++.h>
using namespace std;

auto solve() {
	int n, m, k;
	cin >> n >> m >> k;

	if (m == 1) return false;
	if (k >= n) return false;

	if (m == 2) {
		if (n/2 <= k) return false;
	}

	int x= (n+m-1)/m;
	if (n - x <= k) return false;
	return true;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	cin >> tt;

	for (int i = 1; i <= tt; i++) {
		cout << (solve() ? "YES" : "NO") << '\n';
	}

}


// AC, ad-hoc
