#include <bits/stdc++.h>
using namespace std;

auto run () {
	int n;
	cin >> n;

	vector<int> xs(n);
	for (auto &xi : xs) cin >> xi;


	int gcdall = xs[0];
	for (auto &xi : xs) gcdall = gcd(xi, gcdall);

	if (gcdall != 1) {
		cout << -1 << '\n';
		return;
	}

	int one = 0;
	for (int i = 0; i < n; i++) {
		one += xs[i] == 1;
	}

	if (one) {
		cout << n - one << '\n';
		return;
	}

	
	int m = n*2;
	for (int i = 0; i < n; i++) {
		gcdall = xs[i];
		for (int j = i; j < n; j++) {
			gcdall = gcd(gcdall, xs[j]);
			if (gcdall == 1) {
				m = min(m, j-i+1);
				break;
			}
		}
	}

	cerr << m << '\n';
	cout << m - 1 + n - 1 << '\n';



}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
       	run();
}


// AC, greddy
