#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 2'00'000;
int N;
ll CS[MAXN+1];
string S;

ll psum[2][MAXN+1];
int bits[MAXN+1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	cin >> S;
	S = '#' + S;
	for (int i = 1; i <= N; i++) {
		bits[i] = S[i]-'0';
	}
	for (int i = 1; i <= N; i++) {
		cin >> CS[i];
	}

	for (int i = 1; i <= N; i++) {
		psum[0][i] = psum[0][i-1] + ((ll)((!(i&1))==bits[i]) * CS[i]);
		psum[1][i] = psum[1][i-1] + ((ll)((i&1)==bits[i]) * CS[i]);
	}

	ll ans = 1e18;
	for (int i = 1; i < N; i++) {
		// comecando em 0	
		ll suffcost = psum[1][N]-psum[1][i];
		ans = min(ans, psum[0][i] + suffcost);

		// comecando em 1
		suffcost = psum[0][N]-psum[0][i];
		ans = min(ans, psum[1][i] + suffcost);
	}

	cout << ans << '\n';
}

