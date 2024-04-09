#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;

	int ans = 1'000'000'000;
	for (int i = 0; i*2 <= n; i++) {
		ans = min(ans, i*b + (n-2*i)*a);
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}
}

/*
	AC, brute force	

   1 a 
   2 b
   n
   min que precisa 
 */

