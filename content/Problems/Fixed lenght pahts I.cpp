#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2'00'000;
int N, K;
vector<int> ADJ[MAXN];

int64_t ans;
bool removed[MAXN];
int cnt[MAXN];

int sz[MAXN];

void calcSize(int u, int p = -1) {
	sz[u] = 1;
	for (int v : ADJ[u]) {
		if (v != p and !removed[v]) {
			calcSize(v, u);
			sz[u] += sz[v];
		}
	}
}

int getCentroid(int mxSz, int u, int p = -1) {
	for (int v : ADJ[u]) {
		if (v != p and !removed[v] and sz[v] >= mxSz)
			return getCentroid(mxSz, v, u);
	}
	return u;
}

int mxd;
void dfs(int u, int p, bool upd, int d = 1) {
	if (d > K) return;
	mxd = max(mxd, d);
	upd ? cnt[d]++ : ans += cnt[K-d];

	for (int v : ADJ[u]) {
		if (v != p and !removed[v])
			dfs(v, u, upd, d + 1);
	}
}

void solve(int u) {
	calcSize(u);

	int c = getCentroid(sz[u] >> 1, u);
	removed[c] = true;

	mxd = 0;
	cnt[0] = 1;
	for (int v : ADJ[c]) {
		if (!removed[v]) {
			dfs(v, c, false);
			dfs(v, c, true);
		}
	}

	for (int i = 0; i <= mxd; i++)
		cnt[i] = 0;

	for (int v : ADJ[c]) {
		if (!removed[v])
			solve(v);
	}

}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N -1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		ADJ[u].emplace_back(v);
		ADJ[v].emplace_back(u);
	}

	solve(0);


	cout << ans << '\n';

	return 0;
}
