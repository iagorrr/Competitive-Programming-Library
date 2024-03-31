/*
	> essentialy you can increase one of the coins randomly
*/

#include <bits/stdc++.h>
using namespace std;
using ld = long double;
bitset<101> done[101][101];
ld memo[101][101][101];
ld solve(int i, int j, int k) {
	if (i == 100 or j == 100 or k == 100) return 0;
	if (done[i][j][k]) return memo[i][j][k];

	ld a = (solve(i+1,j,k)+(ld)1) * ((ld)i/(ld)(i+j+k));
	ld b = (solve(i,j+1,k)+(ld)1) * ((ld)j/(ld)(i+j+k));
	ld c = (solve(i,j,k+1)+(ld)1) * ((ld)k/(ld)(i+j+k));
	ld ans = a + b + c;

	done[i][j][k] = 1;

	return memo[i][j][k] = ans;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	cout << fixed << setprecision(10) << solve(a,b,c) << '\n';
}

// AC, expected value, dp
