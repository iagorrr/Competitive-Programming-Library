#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	string s;
	cin >> s;
	
	vector<int> xs(n);
	for (int i = 0; i < n; i++) {
		xs[i] = s[i] - '0';
	}

	int ans = 1;

	for (int sz = 2; sz <= n; sz++) {
		vector<int> ps(n);
		for (int j = 0; j < n; j++) {
			ps[j] += j ? ps[j-1] : 0;
			int bit = (xs[j] + (ps[j]&1))&1;

			if (j+sz > n)
				continue;

			if (!bit) {
				ps[j]++;
				if (j+sz != n) ps[j+sz]--;
			}
		}

		int check = 1;
		for (int j = 0; j < n; j++) 
			check = min(check, (xs[j] + (ps[j]&1))&1);
		ans = check ? sz : ans;
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
	- string binária
	- escolho k consectivos e flip eles
	- quero todos os caracters igual a 1
	- quero o maior K que consigo fazer as operações e ainda deixar tudo em 1 ?
	! foda-se a quantidade de operações

	! N = 5000 Da N^2

	! acho que da ruim quando tu set a alguém lá da frente pra zero é não consegue
	desetar ??
	> não faz sentido aplicar a operação mais de uma vez no mesmo nó

	 ? da pra fazer com sat ?	

	 ? e uma função crescente ?? se deu com x dá com x -1 ?
		???????
	
	? fazer com uma seg ou soma de prefixo pra fazer Nlog ??
		test todos e checo em O(N) ent N^2 dibas
 */

