#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> as(n);
	for (auto &xi : as) cin >>xi;

	vector<int> bs(n);
	for (auto &bi :bs) cin >> bi;

	map<int,int> hs;
	for (int i = 0, p; i < n ;i++) {
		cin >> p;
		p--;
		hs[bs[p]]++;
	}

	long long ans = 0;

	for (auto ai : as) {
		ans += hs[ai];
	}

	cout << ans << '\n';
}

