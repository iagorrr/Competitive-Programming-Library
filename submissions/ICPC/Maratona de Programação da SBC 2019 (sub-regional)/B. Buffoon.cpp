#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> xs(n);
	for (int i = 0; i < n; i++) {
		cin >> xs[i];
	}

	int m = *max_element(xs.begin(), xs.end());

	if (m <= xs.front()) {
		cout << "S\n";
	}
	else {
		cout << "N\n";
	}
}

// AC, ad-hoc
