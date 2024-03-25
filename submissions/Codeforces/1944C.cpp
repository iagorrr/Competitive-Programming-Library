#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	map<int,int> hist;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		hist[x]++;
	}

	set<pair<int,int>> st;
	for (auto [a, b] : hist) {
		st.emplace(b, a);
	}

	set<int> chosed;
	int p = 1;
	while (!st.empty()) {
		auto [qtd, num] = *st.begin();
		if (p & 1) {
			chosed.emplace(num);
			st.erase({qtd,num});
		}	
		else {
			st.erase({qtd,num});
			if (qtd > 1)
				st.insert({qtd-1,num});
		}
		p++;
	}
	for (int i = 0; i < 2*n; i++) {
		if (!chosed.count(i)) {
			cout << i << '\n';
			return;
			}
	}
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

// AC, greddy
