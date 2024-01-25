#include <bits/stdc++.h>
using namespace std;

const int MAXN(10000), MAXM(100000);

int tin[MAXN], low[MAXN], clk;
int isBridge[MAXM];

int N, M, Q;
vector<pair<int, int>> G[MAXN];

void clearall() {
  fill(tin, tin + N, 0);
  fill(low, low + N, 0);
  fill(isBridge, isBridge + M, 0);
  clk = 1;
  for (int i = 0; i < N; i++) {
    G[i].clear();
  }
}

void dfs(int u, int p = -1) {
  tin[u] = low[u] = clk++;

  for (auto [v, i] : G[u]) {
    if (v == p) continue;
    if (tin[v]) {
      low[u] = min(low[u], tin[v]);
    } else {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > tin[u]) {
        isBridge[i] = 1;
      }
    }
  }
}

void findBridges() {
  for (int i = 0; i < N; i++) {
    if (!tin[i]) dfs(i);
  }
}

char vis[MAXN];
bool trypath(int a, int b) {
  if (a == b) return true;
  vis[a] = true;

  for (auto [v, i] : G[a]) {
    if (vis[v]) continue;
    if (!isBridge[i]) continue;
    if (trypath(v, b)) {
      return true;
    }
  }

  return false;
}

void run() {
  clearall();
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].emplace_back(b, i);
    G[b].emplace_back(a, i);
  }

  findBridges();

  while (Q--) {
    int a, b;
    cin >> a >> b;
    a--, b--;

    fill(vis, vis + N, 0);
    if (trypath(a, b)) {
      cout << "Y\n";
    } else {
      cout << "N\n";
    }
  }

  cout << "-\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  for (;;) {
    cin >> N >> M >> Q;
    if (N + M + Q) {
      run();
    } else
      break;
  }
}
