#include <bits/stdc++.h>
using namespace std;

auto run() {
	int n, q;
	cin >> n >> q;

	string s;
	cin >> s;

	vector<string> perms ({"abc","acb","bac","bca","cba","cab"});
	vector<vector<int>> cs(6, vector<int>(n+1));
	for (int i = 0; i < 6; i++) {
		for (int j = 1; j <= n; j++) {
			cs[i][j] = cs[i][j-1] + (s[j-1] !=  perms[i][(j-1)%3]);
		}

	}

	while (q--) {
		int l, r;
		cin >> l >> r;

		int ans = 1e9;
		for (int i = 0; i < 6; i++) {
			ans = min(ans, cs[i][r] - cs[i][l-1]);
		}

		cout << ans << '\n';
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}

/*
   	AC, strings, prefix sum, brute force

	uma string válida vai ser sempre repetições de uma das permutaçoes de abc

		abc acb
		bac bca
		cba cab

	pq quando tu poem um a -> b tu é obrigaod a por um c, e assim por diante

	dai só calcula o custo caso fosse usar qualquer uma das permutações, e pega a menor 
	delas

	vapo vapo

 */
