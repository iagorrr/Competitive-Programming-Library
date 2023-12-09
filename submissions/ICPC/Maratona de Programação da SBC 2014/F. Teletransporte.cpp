#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vll2d = vector<vll>;

const int MAXN(100);
const ll MOD(1'0'000);
ll N, L, S, T;
vll2d ways(MAXN, vll(MAXN));


vll2d prod(vll2d &a, vll2d &b) {
	vll2d c(N, vll(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}

	return c;
}

vll2d pow (vll2d &a, ll p) {
	vll2d res(N, vll(N));

	for (int i = 0; i < N; i++) {
		res[i][i] = 1;
	}

	while (p) {
		if (p&1) res = prod(res, a);
		a = prod(a,a);
		p >>= 1;
	}

	return res;
}


void solve() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ways[i][j] = 0;
		}
	}

	cin >> S >> T;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			int k;
			cin >> k;
			k--;
			ways[i][k]++;
		}
	}

	auto w2 = pow(ways, L);
	cout << w2[S-1][T-1] << '\n';

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (cin >> N >> L) {
		solve();
	}
	
}

/*
 * AC
 * https://www.beecrowd.com.br/judge/pt/problems/view/1713
 * Graphs
 * Matrix Exponiation
 * */
