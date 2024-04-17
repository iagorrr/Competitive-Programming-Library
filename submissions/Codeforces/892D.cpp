#include <bits/stdc++.h>
using namespace std;

using ll = long long;
auto run () {
	int n;
	cin >> n;
	vector<ll> xs(n);
	for (auto &xi : xs) cin >> xi;

	auto  xso = xs;
	sort(xso.begin(), xso.end());

	map<int, int> pos;
	for (int i = 0; i < n; i++) {
		pos[xso[i]] = i;
	}

	vector<int> ans;
	for (int i = 0; i < n; i++) {
		int posxi = pos[xs[i]];
		if (posxi) posxi = posxi -1;
		else posxi = n -1;
		int match = xso[posxi];
		ans.emplace_back(match);
	}

	for (auto i : ans) {
		cout << i << ' ';
	}
	cout << '\n';


}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
       	run();
}


