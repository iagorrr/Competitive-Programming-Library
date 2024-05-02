#include <bits/stdc++.h>
using namespace std;

auto run() {
	int n;
	cin >> n;
	vector<int> xs(n-1);
	for (auto &ai : xs) cin >> ai;

	int cur = 501;
	cout << cur;
	for (int i = 0; i < n-1; i++) {
		cur = cur + xs[i];
		cout << ' ' << cur;
	}
	cout << '\n';

}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	for (int ttt = 1; ttt <= tt; ttt++) {
		run();
	}
}

// AC, greddy, number theory
