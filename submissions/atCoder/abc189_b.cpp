#include <bits/stdc++.h>
using namespace std;

auto run() {
	int n;
	cin >> n;

	int p;
	cin >> p;

	p *= 100;


	for (int i = 0; i < n; i++) {
		int x, pi;
		cin >> x >> pi;
		p = p - (x*pi);
		if (p < 0) {
			cout <<i + 1  << '\n';
			return;
		}
	}
	cout << -1 << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	run();
}


// AC, math
