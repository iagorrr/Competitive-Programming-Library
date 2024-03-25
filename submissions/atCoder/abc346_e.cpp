#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int h, w, m;
	cin >> h >> w >> m;

	vector<tuple<long long, long long, long long>> queries;
	for (int i = 1; i <= h; i++) {
		queries.emplace_back(1, i, 0);
	}
	while (m--) {
		int t, a, x;
		cin >> t >> a >> x;
		queries.emplace_back(t, a, x);
	}

	vector<long long> colorQtd(2*1'00'000 + 1);
	set<int> rows, columns;
	while (!queries.empty()) {
		auto [t, a, x] = queries.back();
		queries.pop_back();
		if (t == 1) {
			if (!rows.count(a))
				colorQtd[x] += w-(int)columns.size();
			rows.emplace(a);
		}
		else {
			if (!columns.count(a))
				colorQtd[x] += h -(int)rows.size();
			columns.emplace(a);
		}
	}

	vector<pair<int, long long>> ans;
	for (int i = 0; i < (int)colorQtd.size(); i++) {
		if (colorQtd[i])
			ans.emplace_back(i, colorQtd[i]);
	}

	cout << ans.size() << '\n';
	for (auto [a, b] : ans) {
		cout << a << ' ' << b << '\n';
	}
}

// AC, ad-hoc
