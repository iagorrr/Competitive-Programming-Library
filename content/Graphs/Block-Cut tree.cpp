/*8<
 * @Title: Block-Cut Tree
 *
 * @Description: Builds the Block-Cut of a undirected graph.
 *
 * @Time: $O(N+M)$
 *
 * @Usage: \textbf{$isGraphCutpoint[u]$} answers how many connected components
 * are created when the node u is removed from the graph, if
 * $isGraphCutpoint[u]$ is greater than $1$, it means that $u$ is a
 * cutpoint.
 *
 * @Memory: $O(N)$
 *
 * @Time: $O(N+M)$
 *
 * @Problems:
 * https://codeforces.com/group/btcK4I5D5f/contest/601720/problem/I
 * >8*/

#pragma once
#include "../Contest/template.cpp"

struct BlockCutTree {
    int n;
    vi idOnTree, tin, low, stk, isGraphCutpoint, isTreeCutpoint;
    vi2d comps, treeAdj;

    BlockCutTree(vi2d &g)
        : n(len(g)), idOnTree(n), tin(n), low(n), isGraphCutpoint(n) {
        rep(i, 0, n) {
            if (!tin[i]) {
                int timer = 0;
                dfs(i, -1, timer, g);
            }
        }

        buildTree();
    }

    void buildTree() {
        int node_id = 0;
        rep(u, 0, n) {
            if (isGraphCutpoint[u]) {
                idOnTree[u] = node_id++;
                isTreeCutpoint.eb(true);

                treeAdj.pb({});
            }
        }

        for (auto &comp : comps) {
            int node = node_id++;
            treeAdj.pb({});
            isTreeCutpoint.eb(false);
            for (int u : comp) {
                if (!isGraphCutpoint[u]) {
                    idOnTree[u] = node;
                } else {
                    treeAdj[node].eb(idOnTree[u]),
                        treeAdj[idOnTree[u]].eb(node);
                }
            }
        }
    }

    void dfs(int u, int p, int &timer, vi2d &g) {
        tin[u] = low[u] = ++timer;
        stk.eb(u);

        for (auto v : g[u]) {
            if (v == p) continue;
            if (!tin[v]) {
                dfs(v, u, timer, g);
                chmin(low[u], low[v]);
                if (low[v] >= tin[u]) {
                    isGraphCutpoint[u] += (tin[u] > 1 or tin[v] > 2);
                    assert(isGraphCutpoint[u]);
                    comps.pb({u});
                    while (comps.back().back() != v) {
                        comps.back().eb(stk.back());
                        stk.ppb();
                    }
                }
            } else
                low[u] = min(low[u], tin[v]);
        }
    }

    int countMandatoryNodesOnPath(int startNode, int endNode);
};
