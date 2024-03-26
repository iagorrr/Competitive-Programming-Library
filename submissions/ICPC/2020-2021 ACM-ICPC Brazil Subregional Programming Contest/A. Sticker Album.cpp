#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;

	if (a >= n) {
		cout << 1 << '\n';
		return 0;
	}

	vector<long double> psum(n+1), dp(n+1);
	for (int i = 1; i <= a; i++)
		dp[i] = 1,
	       	psum[i] = psum[i-1] + 1;


	long double frac = (long double)(b+1)/(long double)(b);
	long double m = (long double)1/(long double)(b - a + 1);
	for (int i = a+1; i <= n; i++) {
		int r = a ? i - a : i - 1;
		int l = max(0, i - b - 1);
		dp[i] = (psum[r] - psum[l])*m + 1;
		if (!a) dp[i] = dp[i] * frac;
		psum[i] = psum[i-1] + dp[i];
	}

	cout << fixed << setprecision(10) << dp[n] << '\n';

}

// AC, expected value dp
