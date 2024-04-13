#include <bits/stdc++.h>
using namespace std;

auto run() {
	string s;
	cin >> s;
	
	map<char, int> h;
	for (auto c : s) {
		h[c]++;
	}

	bool ans = 1;
	for (int i = 1; i <= 2*(int)s.size(); i++) {
		int k = 0;
		for (auto [_, q] : h) k += (q == i);
		ans &= (k == 2 or k == 0);
		//cerr << i << ' ' << k << ' ' << ans << '\n';
	}

	cout << (ans ? "Yes" : "No") << '\n';

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}

