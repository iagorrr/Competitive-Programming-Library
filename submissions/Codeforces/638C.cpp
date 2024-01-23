#include <bits/stdc++.h>
using namespace std;

const int maxn(2'00'000);
vector<int> g[maxn];
map<pair<int,int>, int> edgeid;
int n;

int mdays;
vector<int> ans[maxn];
void dfs(int u = 0, int ptime=-1, int p = -1) {
	int time = 0;
	for (auto v : g[u]) {
		if (v == p) continue;
		time += ptime == time;
		ans[time].emplace_back(edgeid[{min(u,v), max(u,v)}]);
		dfs(v, time, u);
		time++;
	}
	mdays = max(mdays,time-1);
}

void run() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		edgeid[{min(a, b), max(a, b)}] = i;

		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}

	dfs();
	cout << mdays+1 << '\n';
	for (int i = 0; i <= mdays; i++) {
		cout << ans[i].size();
		for (auto j : ans[i]) cout << ' ' << j;
		cout << '\n';
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	run();
}

/*
   AC
   graphs
   trees
   https://codeforces.com/problemset/problem/638/C 
 */
