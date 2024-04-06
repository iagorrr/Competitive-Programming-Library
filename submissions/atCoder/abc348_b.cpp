#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	vector<pair<ll,ll>> pts(n);
	for (auto &[a, b] : pts) cin >> a >> b;

	auto dist = [&](int i, int j) {
		ll a = pts[i].first-pts[j].first;
		ll b = pts[i].second-pts[j].second;
		return  a*a + b*b;
	};

	for (int i = 0; i < n; i++) {
		ll mind = -1;
		int best = i;

		for (int j = 0; j < n; j++) {
			if (j == i) continue;
			if (dist(i,j) > mind) {
				best = j;
				mind = dist(i, j);
			}
		}
		cout << best + 1 << '\n';
	}
}


// AC, ad-hoc
