#include <bits/stdc++.h>
using namespace std;

auto run() {
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a;
	cin >> b;

	vector<int>pos1, pos0;
	for (int i = 0; i < m; i++) {
		if (b[i] == '0') {
			pos0.push_back(i);
		}
		else
			pos1.push_back(i);
	}

	reverse(pos0.begin(), pos0.end());
	reverse(pos1.begin(), pos1.end());

	int curpos = -1;
	int i = 0;
	int ans = 0;
	for (i = 0; i < n; i++) {
		while(pos1.size() and pos1.back() <= curpos)
			pos1.pop_back();

		while(pos0.size() and pos0.back() <= curpos)
			pos0.pop_back();

		if (a[i] == '1') {
			if (pos1.empty()) break;
			else {
				curpos = pos1.back();
				pos1.pop_back();
			}
			ans = max(ans, i+1);
		}
		else {
			if (pos0.empty()) break;
			else {
				curpos = pos0.back();
				pos0.pop_back();
			}
			ans = max(ans, i+1);
		}
	}

	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	for (int ttt = 1; ttt <= tt; ttt++) {
		run();
	}
}

// AC, strings, greddy
