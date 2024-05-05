#include <bits/stdc++.h>
using namespace std;


using ll = long long;
const int maxn = 400;

const ll oo = maxn * 1'0'000ll;

int n, m;
ll temp[maxn];
vector<pair<ll,int>> adj[maxn];

ll dist[maxn][maxn];
ll fdist[maxn][maxn];

int RANK[maxn];

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		dist[i][i] = 0;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				dist[i][j] = oo;
				fdist[i][j] = oo;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cin >> temp[i];
	}

	for (int i = 0, a, b,c; i < m; i++) {
		cin >> a >> b >> c;
		a--, b--;

		dist[a][b] = dist[b][a] = c;
		fdist[a][b] = fdist[b][a] = c;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}
	

	int q;
	cin >> q;
	using a4 = array<int,5>;
	vector<a4> qs(q);
	vector<int> ans(q);
	int qid = 0;
	for (auto &[a,b,k,t, id] : qs) {
		cin >> a >> b >> k >> t;

		id = qid++;
		a--, b--;
	}

	// ordena pelo k
	sort(qs.begin(), qs.end(), [&](const a4 &a, const a4 &b) -> bool{
			return a[2] < b[2];
	});

	// pegar o rank dos mais frios
	vector<pair<int,int>> temp_id;
	temp_id.reserve(n);
	for (int i = 0; i < n; i++) {
		temp_id.emplace_back(temp[i], i);
	}
	sort(temp_id.begin(), temp_id.end());

	RANK[temp_id[0].second] = 1;
	for (int i = 1; i < n; i++) {
		auto [pt, pi] = temp_id[i-1];
		auto [ct, ci] = temp_id[i];
		RANK[ci] = RANK[pi] + (ct > pt);
	}



	int pi = 0; // proximo id a ser adicionado
	for (int i = 0; i < q; i++) {
		auto &[a, b, k, t, qid] = qs[i];

		if (t) continue;

		while (pi < n and RANK[temp_id[pi].second] <= k) {
			auto x = temp_id[pi].second;
			for (int u = 0; u < n; u++) {
				for (int v = 0; v < n; v++) {
					// usa x pra relaxar entre u e v
					ll du = dist[u][x], dv = dist[x][v];
					if (du + dv < dist[u][v]) {
						dist[u][v] = du + dv;
					}
				}
			}
			pi++;
		}

		ans[qid] = dist[a][b];
	}


	// pegar o rank dos mais quentes
	sort(temp_id.begin(), temp_id.end(), greater<>());
	RANK[temp_id[0].second] = 1;
	for (int i = 1; i < n; i++) {
		auto [pt, pi] = temp_id[i-1];
		auto [ct, ci] = temp_id[i];
		RANK[ci] = RANK[pi] + (ct < pt);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j< n; j++) {
			dist[i][j] = fdist[i][j];
		}
	}


	pi = 0; // proximo id a ser adicionado
	for (int i = 0; i < q; i++) {
		auto &[a, b, k, t, qid] = qs[i];

		if (!t) continue;

		while (pi < n and RANK[temp_id[pi].second] <= k) {
			auto x = temp_id[pi].second;
			for (int u = 0; u < n; u++) {
				for (int v = 0; v < n; v++) {
					// usa x pra relaxar entre u e v
					ll du = dist[u][x], dv = dist[x][v];
					if (du + dv < dist[u][v]) {
						dist[u][v] = du + dv;
					}
				}
			}
			pi++;
		}

		ans[qid] = dist[a][b];
	}

	for (int i = 0; i < q; i++) {
		auto ai = ans[i];
		cout << (ai == oo ? -1 : ai) << '\n';
	}
}


// AC, graphs, floyd warshall
