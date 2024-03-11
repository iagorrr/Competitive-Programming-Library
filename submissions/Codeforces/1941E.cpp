#include <bits/stdc++.h>
using namespace std;


using ll = long long;
const ll OO = 1e18;


void solve() {
	int n, m, k, d;
	cin >> n >> m >> k >> d;

	vector<vector<ll>> lines(n, vector<ll>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lines[i][j];
		}
	}

	vector<ll> costs(n);
	for (int i = 0; i < n; i++) {
		set<pair<ll, int>> st;
		st.emplace(1, 0);
		for (int j = 1; j < m; j++) {
			while (st.begin()->second < j -d-1)
				st.erase(st.begin());

			if (j == m-1)
				costs[i] = st.begin()->first + 1;

			st.emplace(st.begin()->first + lines[i][j]+1, j);
		}
	}


	ll ans = OO;
	for (int i = 0; i + k - 1< n; i++) {
		ll cur = 0;
		for (int j = 0; j < k; j++) {
			cur += costs[i+j];
		}
		ans = min(ans, cur);
	}

	cout << ans << '\n';
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}

// AC, greddy, data structures
