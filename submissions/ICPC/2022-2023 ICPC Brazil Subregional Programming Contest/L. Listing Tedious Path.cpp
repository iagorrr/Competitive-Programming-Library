#include <bits/stdc++.h>
using namespace std;

const int maxn(1'00'000);
int cs[maxn];
vector<pair<int, int>> adj[maxn];
int n;
long long ans[maxn];
int hist[maxn];
map<pair<int, int>, int> edgeid;

map<int, int> hist_node[maxn];

int bigchild[maxn], sz[maxn];
void getsz(int u = 0, int p = -1) {
  sz[u] = 1;

  int best = -1;
  for (auto [v, idx] : adj[u]) {
    if (v != p) {
      getsz(v, u);
      sz[u] += sz[v];
      if (best == -1 or sz[v] > sz[best]) best = v;
    }
  }

  bigchild[u] = best;
}

void dfs(int u = 0, int p = -1) {
  if (bigchild[u] != -1) {
    dfs(bigchild[u], u);

    int idx = edgeid[{u, bigchild[u]}];
    for (auto [c, qtd] : hist_node[bigchild[u]]) {
      ans[idx] +=
        (long long)qtd * (long long)(hist[c] - qtd);
    }
    hist_node[u].swap(hist_node[bigchild[u]]);
  }

  hist_node[u][cs[u]]++;

  for (auto [v, idx] : adj[u]) {
    if (v == p or v == bigchild[u]) continue;

    dfs(v, u);

    for (auto [c, qtd] : hist_node[v]) {
      hist_node[u][c] += qtd;
      ans[idx] +=
        (long long)qtd * (long long)(hist[c] - qtd);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> cs[i], cs[i]--;
    hist[cs[i]]++;
  }

  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v, i);
    adj[v].emplace_back(u, i);
    edgeid[{u, v}] = i;
    edgeid[{v, u}] = i;
  }

  getsz();
  dfs();

  for (int i = 0; i < n - 1; i++) {
    cout << ans[i] << " \n"[i == n - 2];
  }
}

// AC, small to large
