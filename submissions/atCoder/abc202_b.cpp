#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	for (auto &c : s) {
		if (c == '6') c = '9';
		else if (c == '9') c = '6';
	}

	reverse(s.begin(), s.end());
	cout << s << '\n';
}

