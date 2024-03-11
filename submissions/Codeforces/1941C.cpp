#include <bits/stdc++.h>
using namespace std;

int solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;


	int ans = 0;
	for (int i = 0; i < n;) {
		string a = s.substr(i, 3);
		string b = s.substr(i, 5);
		if (b == "mapie") {
			i += 5;
			ans++;
		}
		else if (a == "pie" or a == "map"){
			i += 3;
			ans++;
		}
		else i++;
		// cout << a << ' ' << b << '\n';
	}

	return ans;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cout << (solve())  << '\n';
	}
}


// AC, strings, greddy
