/*8<
  @Title:

    Find Bridges

  @Description:

    Find every bridge in a \textbf{undirected}
    connected graph.

  @Warning:

    Remember to read the graph as pair where the
    second is the id of the edge !

  @Time : $O(N + M) $
>8*/
#pragma once
#include "../Contest/template.cpp"

const int MAXN = 1e5 + 5, MAXM = 1e5 + 5;
int N, M, clk, tin[MAXN], low[MAXN], isBridge[MAXM];
vector<pii> G[MAXN];

void dfs(int u, int pe = -1) {
    tin[u] = low[u] = clk++;

    for (auto [v, i] : G[u]) {
        if (i == pe) continue;
        if (tin[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, i);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) {
                isBridge[i] = 1;
            }
        }
    }
}

void findBridges() {
    fill(tin, tin + N, 0);
    fill(low, low + N, 0);
    fill(isBridge, isBridge + M, 0);
    clk = 1;
    for (int i = 0; i < N; i++) {
        if (!tin[i]) dfs(i);
    }
}
