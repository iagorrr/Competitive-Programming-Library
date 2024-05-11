#include <bits/stdc++.h>
using namespace std;


const int maxn = 1'00'000;
vector<int> adj[maxn];
int pai[maxn];

int best_son[maxn];
void sobe(int u, int subi = 0)  {
	best_son[u] = max(best_son[u], subi+1);
	if (u)
		sobe(pai[u], subi + 1);
}

int sobe2(int u, int subi = 1) {
	if (subi >= best_son[u]) {
		best_son[u] = 1e9;
		if (!u) return 1;
		return sobe2(pai[u], subi+1) + 1;
	}
	else {
		return 0;
	}
}


int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 1, x; i < n; i++) {
		cin >> x;
		x--;
		adj[x].push_back(i);
		pai[i] = x;
	}

	for (int i = 0; i  < n; i++) {
		if (adj[i].size() == 0) {
			sobe(i);
		}
	}


	vector<int> v;
	for (int i = 0; i  < n; i++) {
		if (adj[i].size() == 0) {
			auto c = sobe2(i);
			v.push_back(c);
		}
	}


	sort(v.begin(), v.end(), greater<int>());

	int ans = 0;
	for (int i = 0; i < k; i++) {
		ans += v[i];
	}

	cout << ans << '\n';

}


// AC, trees, greddy
