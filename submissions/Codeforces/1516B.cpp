#include <bits/stdc++.h>
using namespace std;

auto run() {
	int n;
	cin >> n;

	vector<int> xs(n);
	for (auto &xi : xs) cin >> xi;

	if (xs.empty()) {
		cout << "YES\n";
		return;
	}

	if (xs.size() == 1) {
		cout << "NO\n";
		return;
	}

	vector<int> pxor(n+1);
	for (int i = 1; i <= n; i++) {
		pxor[i] = pxor[i-1] ^ xs[i-1];
	}



	int pre_xor = 0;
	for (int i = 0; i < n-1; i++) {
		pre_xor ^= xs[i];
		int pre_xor2 = 0;
		for (int j = i + 1; j < n; j++) {
			pre_xor2 ^= xs[j];
			if (pre_xor == pre_xor2) {
				int sufxor =  (pxor[n]^pxor[j+1]);
				// cerr << i << ' ' << j << ' ' << sufxor << '\n';
				if (j == n-1 or sufxor == pre_xor) {
					cout << "YES\n";
					return;
				}
			}

		}
	}


	cout << "NO\n";
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;

	while(tt--)
		run();
}

// AC, bruteforce, bitwise operations
