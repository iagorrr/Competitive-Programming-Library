#include <bits/stdc++.h>
using namespace std;

int count(vector<pair<int,int>> &xs) {
	set<int> dists;
	for (auto [i, j] : xs) {
		for (auto [i2, j2] : xs) {
			dists.emplace(abs(i2-i) + abs(j-j2));
		}
	}

	return dists.size();
}

auto run() {
	int n;
	cin >> n;

	if (n == 3) {
		cout << "2 1\n";
		cout << "2 3\n";
		cout << "3 1\n";
		cout << '\n';
		return;
	}

	vector<pair<int,int>> ans;
	ans.push_back({1,1});
	ans.push_back({n,n});

	for (int i = 1; i <= n - 2 - 1; i++) {
		ans.push_back({1,1+i});
	}

	if (n>2)
	ans.push_back({1 + (n+1)/2, 1});


	// cerr << "count: " << count(ans) << '\n';

	for (auto [i, j] : ans) {
		cout << i << ' ' << j << '\n';
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

// AC, constructive
