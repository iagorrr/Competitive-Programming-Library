#include <bits/stdc++.h>
using namespace std;

using ld = long double;

auto run() {
	int n;
	cin >> n;


	ld ans = 0.0;
	for (int i = 1; i < n; i++) {
		ans = ans + (ld) n / (ld)i;
	}
	cout << fixed << setprecision(10) << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}

// AC, math, expected value
