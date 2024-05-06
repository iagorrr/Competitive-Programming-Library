#include <bits/stdc++.h>
using namespace std;

/*
	busca binária pra achar quantas vezes vai repetir cada um
	check usando cada número quanto precisar
	vapo vapo
 */

auto run() {
	int n, k;
	cin >> n >> k;

	map<int,int> hist;
	vector<int> xs(n);
	for (auto &ai : xs) {
		cin >> ai;
		hist[ai]++;
	}
	
	int rep = 0;
	auto check = [&](int x) -> bool{
		int q = 0;
		for (auto &[_, qtd] : hist) {
			q += qtd / x;
		}
		return q >= k;
	};
	for (int l = 1, r = n; l <= r; ) {
		int mid = midpoint(l, r);
		if (check(mid)) {
			rep = max(rep, mid);
			l = mid + 1;
		}
		else r = mid - 1;
	}

	int k2 = 0;
	for (auto &[x, q]  : hist) {
		if (k2 == k) break;
		for (int i = 0; i < q/rep and k2 < k; i++) {
			cout << x << ' ';
			k2++;
		}
	}
	cout << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;

	while (t--) {
		run();
	}
}


// AC, constructive, binary search, greddy
