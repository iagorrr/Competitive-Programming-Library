#include <iostream>
#include <vector>
#include <set>
#include <bitset>
#include <string.h>

const int maxn(5'0'000);
std::vector<int> adj[maxn];
int n, m, q;

int scc_id[maxn], tin[maxn], timer = 1, num_scc;
std::vector<int> stk;
int get_scc_id(int u = 0){
	int low = tin[u] = timer++, szin = (int)stk.size();
	stk.emplace_back(u);

	for (auto v : adj[u]) {
		if (scc_id[v] == -1) {
			low = std::min(low, tin[v] ? tin[v] : get_scc_id(v));
		}
	}

	if (tin[u] == low) {
		for (int i = szin; i < (int)stk.size(); i++) {
			scc_id[stk[i]] = num_scc;
		}
		num_scc++;
		stk.resize(szin);
	}

	return low;
}

std::set<int> sccadj[maxn];
void buildSccGraph() {
	for (int u = 0; u < n; u++) {
		for (auto v : adj[u]) {
			if (scc_id[u] != scc_id[v]) {
				sccadj[scc_id[u]].emplace(scc_id[v]);
			}
		}
	}
}

std::bitset<maxn> reach[maxn];
void solve(int u) {
	if (reach[u][u]) return;

	reach[u][u] = 1;
	for (int v : sccadj[u]) {
		solve(v);
		reach[u] |= reach[v];
	}
}

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	memset(scc_id, -1, sizeof scc_id);

	std::cin >> n >> m >> q;

	for (int i = 0, u, v; i < m; i++) {
		std::cin >> u >> v;
		u--, v--;
		adj[u].emplace_back(v);
	}
	
	stk.reserve(n);
	for (int i = 0; i < n; i++) 
		if (!tin[i]) get_scc_id(i);
	buildSccGraph();



	for (int i = 0; i < n; i++) {
		solve(scc_id[i]);
	}

	while (q--) {
		int u, v;
		std::cin >> u >> v;
		u--, v--;

		std::cout << (reach[scc_id[u]][scc_id[v]] ? "YES" : "NO") << '\n';
	}
}

// AC,  scc, bitset
