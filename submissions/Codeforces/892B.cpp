#include <bits/stdc++.h>
using namespace std;

auto run () {
	int n;

	cin >> n;

	vector<int> xs(n);
	for (auto &xi : xs) {
		cin >>xi;
	}

	int ans = n;

	int cur = xs.back();
	for (int i = n -2; i >= 0; i--) {
		if (cur) {
			ans--;
		}
		cur = max(xs[i], cur-1);
	}

	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
       	run();
}

// AC, greddy
