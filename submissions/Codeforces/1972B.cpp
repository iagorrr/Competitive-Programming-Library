#include <bits/stdc++.h>
using namespace std;


auto run() {
	int n;
	string s;

	cin >> n >> s;

	int qu = count(s.begin(), s.end(), 'U');

	if (qu&1) {
		cout << "YES\n";
	}
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;

	while (tt--)
		run();
}

// AC, games
