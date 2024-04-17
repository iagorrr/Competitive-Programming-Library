#include <bits/stdc++.h>
using namespace std;

auto run() {
	string s;
	cin >> s;

	bool ok = 1;
	for (int i=  0; i < 3; i++) {
		ok &= (s[i] == s[0]);
	}

	cout << ( ok ? "Won" : "Lost") << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	run();
}

// AC, ad-hoc
