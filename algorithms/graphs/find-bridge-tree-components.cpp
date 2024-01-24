int n;
const int MAXN(3'00'000);
vi g[MAXN], vi stck;
int tin[MAXN], low[MAXN], comp[MAXN], qtdcomps, clk;
void dfsb(int u, int p) {
	low[u] = tin[u] = ++clk;
	stck.emplace_back(u);

	for (auto v : g[u]) {
		if (!tin[v]) {
			dfsb(v, u);
			low[u] = min(low[u], low[v]);
		}
		else if(v!=p) {
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
