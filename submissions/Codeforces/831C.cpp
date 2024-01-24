#include<bits/stdc++.h>
using namespace std;

const int MAXN(2'00'000);
int N, X;
vector<int> G[MAXN];
int da[MAXN], db[MAXN];

void dfsb(int u = X, int p = -1, int d = 0) {
	db[u] = d;
	for (auto v : G[u])  {
		if (v == p) continue;
		dfsb(v, u, d+1);
	}

}


void dfsa(int u = 0, int p = -1, int d = 0) {
	da[u] = d;
	for (auto v : G[u])  {
		if (v == p) continue;
		dfsa(v, u, d+1);
	}

}


void run() {
	cin  >> N >> X;

	X--;
	for (int i = 0; i < N-1; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}

	dfsa(), dfsb();

	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (da[i] <= db[i]) continue;
		ans = max(ans, 2*da[i]);
	}

	cout << ans << '\n';

}
int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	run();
}

