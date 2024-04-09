#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> as(n), bs(m);
	for (auto &ai : as) cin >> ai;
	for (auto &bi : bs) {
		cin >> bi;
	}


	map<int, int> hb;
	for (auto &bi : bs) hb[bi]++;

	int k2 = 0;
	map<int,int> ha;
	for (int i = 0; i < m; i++) {
		if (hb[as[i]]) {
			ha[as[i]]++;
			if (ha[as[i]] <= hb[as[i]]) k2++;
		}
	}

	int ans = k2 >= k;
	for (int l = 0, r = m; r < n; l++, r++) {
		ll al = as[l], ar = as[r];

		if (hb[al]) {
			ha[al]--;
			if (ha[al] < hb[al]) k2--;
		}

		if (hb[ar]) {
			ha[ar]++;
			if (ha[ar] <= hb[ar]) k2++;
		}

		ans += k2 >= k;
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
   	AC, ad-hoc
	array A com N   
	array B com M

	M <= N
	
	C é top se da pra ordenar tal que pelo
	menos K deles da match com B

	bora ver os subsegmentos de A de tamnaho M e ver 
	quantos deles são top 

	> acho que da pra fazer tipo um slide window...
	? n basta que C tenha K elementos em comum com B pra ser top ??
		> acho que sim né, seta os K nas posições que da match
		e o resto foda-se
		? e quando é 
 */

