#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// monta a bridge tree !
// dps pega o diâmentro
#define all(x) x.begin(), x.end()
vector<vector<int>> g;
int n, m;

vector<int> tin, low, mark, stck, comp;
int qtdcomps;
int t = 0;
void dfs(int u, int p) {
	low[u] = tin[u] = ++t;
	mark[u] = 1;
	stck.emplace_back(u);

	for (auto v : g[u]) {
		if (mark[v] == 0) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		}
		else {
			if (v == p) continue;
			low[u] = min(low[u], tin[v]);
		}

	}

	if (low[u] == tin[u]) {
		qtdcomps++;
		int v2;
		do {
			v2 = stck.back();
			comp[v2] = qtdcomps;
			stck.pop_back();
		}while(v2 != u);

	}
}

vector<set<int>> tree;
int maxd;

vector<int> vis2;
pair<int,int> bfs(int u){
	vis2.resize(n+1);
	fill(all(vis2), 0);
	queue<pair<int,int>> q;
	q.emplace(u, 0);
	vis2[u] = 1;
	pair<int, int> ans = {u, 0};

	while(!q.empty()) {
		auto [v, d] = q.front();
		if (d > ans.second){
			ans = {v, d};
		}
		q.pop();
		for (auto v2 : tree[v]) {
			if (vis2[v2]) continue;
			vis2[v2] = true;
			q.emplace(v2, d+1);
		}
	}
	return ans;

}
void getdiameter() {
	auto [u, d] = bfs(1);
	auto [v, d2] = bfs(u);
	maxd = d2;
}

void run() {
	cin >> n >> m;
	g.resize(n+1);
	tin.resize(n+1);
	low.resize(n+1);
	mark.resize(n+1);
	comp.resize(n+1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}

	dfs(0, -1);

	tree.resize(n+1);
	for (int i = 0; i < n; ++i) {
			for  (auto j : g[i]) {
				if (comp[i] == comp[j]) continue;
				tree[comp[i]].emplace(comp[j]);
				tree[comp[j]].emplace(comp[i]);
			}

	}

	getdiameter();

	cout << maxd << '\n';

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	run();
}

