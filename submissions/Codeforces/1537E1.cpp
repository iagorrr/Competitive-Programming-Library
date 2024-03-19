#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	string prev = s;
	string ans; ans.push_back(prev[0]);

	for (int i = 1, p1 = 1, p2 = 0; i < k; i++) {
		char c1 = prev[p1%((int)prev.size())];
		char c2 = ans[p2%((int)ans.size())];
		if (c1 < c2) {
			ans.push_back(c1);
			p1++;
			p2 = 0;
		}
		else if (c1 > c2) {
			prev = ans;
			p1 = 0;
			p2++;
			ans.push_back(c2);
		}
		else {
			ans.push_back(c2);
			p1++, p2++;
		}
	}

	cout << ans << '\n';

}
