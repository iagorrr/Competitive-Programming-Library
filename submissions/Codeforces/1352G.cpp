#include <bits/stdc++.h>
using namespace std;

auto run() {
	int n;
	cin >> n;

	if (n  <= 3) {
		cout << -1 << '\n';
		return;
	}

	for (int i = n - !(n&1); i > 0; i -= 2) {
		cout << i << ' ';
	}
	cout << 4 << ' ' << 2;
	for (int i = 6; i <= n; i += 2) cout << ' '<< i;

	cout << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;

	while (t--) {
		run();
	}

}


// AC, constructive algorithms
