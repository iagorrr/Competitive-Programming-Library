#include <bits/stdc++.h>
using namespace std;

auto run() {
	string s;
	cin >> s;
	string t;
	cin >> t;

	s.push_back('x');

	char a = tolower(t[0]);
	char b = tolower(t[1]);
	char c = tolower(t[2]);

	string s2;
	for (auto c2 : s) {
		if (c2 != a and c2 != b and c2 != c) continue;
		s2.push_back(c2);
	}

	int cnt = 0;
	for (auto c2 : s) {
		if (cnt == 0 and c2 == a) cnt++;
		else if (cnt == 1 and c2 == b) cnt++;
		else if (cnt == 2 and c2 == c) cnt++;
	}

	cout << (cnt == 3 ? "Yes" : "No") << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}

