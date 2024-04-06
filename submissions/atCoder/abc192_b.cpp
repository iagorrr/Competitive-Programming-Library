#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;

	int n = (int)s.size();

	bool odd, even;
	odd = even = 1;

	for (int i = 0; i < n; i += 2) {
		odd &= (s[i] != toupper(s[i]));
	}

	for (int i = 1; i < n; i += 2) {
		even &= (s[i] == toupper(s[i]));
	}

	cout << ((odd and even) ?  "Yes" : "No") << '\n';

}

// AC, strings, implementation
