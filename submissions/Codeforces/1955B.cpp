#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll grid[500][500];
void solve() {
	int n;
	ll c, d;
	cin >> n >> c >> d;
	multiset<int> st;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			st.emplace(x);
		}
	}

	int f = *st.begin();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int row = f + d * j;
			int cell = row + i * c;
			if (st.find(cell) == st.end()) {
				cout << "NO\n";
				return;
			}
			st.erase(st.find(cell));
		}
	}

	cout << "YES\n";
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}
}

/*
	AC, math, ad-hoc	
 */

