#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	vector<int> xs(n);
	for (int i = 0; i < n; i++) {
		cin >> xs[i];
	}

	vector<int> ans;
	for (int i = 0; i+1 < n; i++) {
		ans.emplace_back(xs[i] * xs[i+1]);
	}

	for (auto a : ans) {
		cout << a << ' ';
	}
	cout << '\n';



}

// AC, implementation
