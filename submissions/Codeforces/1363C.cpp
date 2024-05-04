#include <bits/stdc++.h>
using namespace std;

auto run() {
	int n, x;
	cin >> n >> x;

	int dgx = 0;
	for (int i = 0, a, b; i < n -1; i++) {
		cin >> a >> b;
		dgx += (a == x or b == x);
	}


	cout << ( (dgx == 1 or  n == 1 or !(n&1)) ? "Ayush" : "Ashish") << '\n';

}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;

	while(tt--)
		run();
}


// AC, games, trees
