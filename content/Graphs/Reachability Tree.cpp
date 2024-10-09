#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20000 + 100;
int dsu[MAXN];
int n;
const int MAXM = 100000;
int m;
int U[MAXM], V[MAXM];
vector<int> adj[MAXN];
int getRoot(int u) {
  if (u == dsu[u]) return u;
  return dsu[u] = getRoot(dsu[u]);
}

void addEdge(int u, int v) {
  u = getRoot(u);
  v = getRoot(v);

  dsu[n] = n;
  dsu[u] = dsu[v] = n;

  adj[n].push_back(u);
  if (u != v) adj[n].push_back(v);

  ++n;
}

void build() {
  for (int i = 0; i < n; ++i) dsu[i] = i;
  for (int i = 0; i < m; ++i) addEdge(U[i], V[i]);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
