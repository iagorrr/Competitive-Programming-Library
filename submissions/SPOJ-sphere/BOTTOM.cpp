#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
using ll = long long;

int n, m;
vector<vector<int>> g, tg;

int qtdcomp = 0;
vector<int> vis, comp;
vector<int> todo;

void getorder(int u) {
	vis[u] = 1;
	for (auto v : g[u]) {
		if (!vis[v]) getorder(v);
	}
	todo.emplace_back(u);
}

void markcomp(int u, int compid) {
	comp[u] = compid;
	for (auto v : tg[u]) {
		if(!comp[v]) markcomp(v, compid);
	}

}

vector<set<int>> cg;

void gen() {
	vis.resize(n);
	fill(all(vis), 0);
	comp.resize(n);
	fill(all(comp), 0);

	todo.clear();
	for (int i =0 ; i < n; i++) {
		if (!vis[i]) getorder(i);
	}

	reverse(all(todo));

	qtdcomp = 0;
	for (auto u : todo) {
		if (!comp[u]) {
			markcomp(u, ++qtdcomp);
		}
	}

	cg.resize(qtdcomp+1);
	for (int i = 1; i <= qtdcomp; i++)cg[i].clear();

	for (int i = 0; i < n; i++) {
		for (auto j : g[i]) {
			int ci = comp[i];
			int cj = comp[j];
			if (ci != cj)
			cg[ci].emplace(cj);
		}
	}

}


void run() {
	cin >> m;
	g.resize(n);
	tg.resize(n);

	for (int i = 0; i < n; i++) {
		g[i].clear();
		tg[i].clear();
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].emplace_back(b);
		tg[b].emplace_back(a);
	}

	gen();

	/*
	cout << "comps:\n";
	for (int i = 0;  i <n; i++) {
		cout << i << ' ' << comp[i] << endl;
	}
	return;
	*/

	vector<int> ans;
	for (int i = 0; i < n; i++) {
		int ci = comp[i];
		if (cg[ci].size() == 0) ans.emplace_back(i);
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] + 1 << " \n"[(int)i==ans.size()-1];
	}
	if (ans.empty()) cout << '\n';


}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (cin >> n) {
		if(n)
			run();
		else break;
	}
}

/*
 * graphs
 * strongly connected components
 * kosajaru
 * https://vjudge.net/problem/SPOJ-BOTTOM
 * */
