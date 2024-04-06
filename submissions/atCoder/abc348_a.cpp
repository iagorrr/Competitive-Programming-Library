#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for (int i  = 1; i <= n; i++) {
		if (i%3) cout << 'o';
		else cout << 'x';
	}
	cout << '\n';
}


// AC, ad-hoc
