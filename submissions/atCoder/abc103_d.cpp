#include <bits/stdc++.h>
using namespace std;

const int maxn(1'00'000);
int n, m;

set<pair<int,int>> asks;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		tie(a, b) = minmax({a,b});
		asks.emplace(a, b);
	}

	multiset<int> endpoint;
	int ans = 0;
	for (int i = 1; i < n; i++) {
		while (asks.size()) {
			auto [l, r] = *asks.begin();
			if (l > i) break;
			asks.erase(asks.begin());
			endpoint.emplace(r);
		}


		if (endpoint.size() and *endpoint.begin() <= i+1) {
			ans++;
			endpoint.clear();
		}

	}

	cout << ans << '\n';
}

// AC, greddy
