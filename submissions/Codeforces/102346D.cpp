#include <bits/stdc++.h>
using namespace std;

const int maxn(1'00'000);
int n, k, ps[maxn], bs[maxn], ans, mdepth[maxn], bson[maxn];
priority_queue<int> pq;
vector<int> g[maxn];

void getmax(int u = 0, int p = -1) {
	mdepth[u] = 1, bson[u] = -1;
	for (auto v : g[u]) {
		if (v == p) return;
		getmax(v, u);
		if (mdepth[v] +1> mdepth[u]) {
			mdepth[u] = mdepth[v] + 1;
			bson[u] = v;
		}
	}
}

void calc(int u = 0, int p = -1, int d = 1) {
	if (bson[u] == -1) {
		pq.emplace(d);
		return;
	}

	for (auto v : g[u]) {
		if (v == p) continue;
		if (v == bson[u])
			calc(v, u,  d + 1);
		else
			calc(v, u, 1);
	}
}	

void run() {
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		cin >> ps[i];
		ps[i]--;
		g[ps[i]].emplace_back(i);
	}

	getmax();
	calc();

	while(not pq.empty() and k--) {
		ans += pq.top();
		pq.pop();
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	run();
}

/*
   AC
   greeddy
   graphs
   dfs
 */
