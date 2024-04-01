#include <bits/stdc++.h>
using namespace std;

int xs[] = {1, 3, 6, 10, 15};
#define int long long

using ll = long long;

ll brute(int n, int i) {
	if (i == 0) return n;
	if (i == -1) return 1e9;
	if (xs[i] > n) return brute(n, i-1);
	ll best = 1e9;
	for (int q = n / xs[i]; q >= 0; q--)  {
		ll cur = brute(n - (xs[i]*q), i-1) + q;
		if (cur > best) break;
		best = min(cur, best);
	}
	return best;
}

void solve() {
	int n;
	cin >> n;

	cout << brute(n, 5-1) << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;

	while (t--) {
		solve();
	}


}

/*
   	AC, brute force

	? brute force com backing track ?
		> coloca a quandidade máxima e vai decrescendo
		> sempre que a achar uma resposta guarda, dai se passar
		da menor que tem não continua
		> acho que sempre fica perto de dar tudo pro maior, com uma
		variaçãozinha ou outra
		

 */
