#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < 1'00'000; i++) {
		if (i * 100 > n) {
			cout << (i*100 - n) << '\n';
			return 0;
		}
	}
}

// AC, ad-hoc
