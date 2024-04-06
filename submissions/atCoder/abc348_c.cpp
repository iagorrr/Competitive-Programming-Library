#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	vector<pair<ll,ll>> pts(n);
	map<int, vector<int>> minc;
	for (auto &[a, b] : pts){
	       	cin >> a >> b;
		minc[b].emplace_back(a);
	}

	int ans = -1;
	for (auto &[_, vs] : minc) {
		sort(vs.begin(), vs.end());
		ans = max(ans, *vs.begin());
	}
	cout << ans << '\n';

}

// AC, ad-hoc
