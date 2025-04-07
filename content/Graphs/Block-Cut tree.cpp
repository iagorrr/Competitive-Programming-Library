/*
 * @Title: Block-Cut Tree
 * @Description:
 *      Builds the Block-Cut of a undirected graph.
 * @Time: $O(N+M)$
 * @Memory: $O(N)$
 * @Problems:
 *      https://codeforces.com/group/btcK4I5D5f/contest/601720/problem/I
 * */
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
                low[u] = min(low[u], low[v]);
                if (low[v] >= tin[u]) {
                    isGraphCutpoint[u] = (tin[u] > 1 or tin[v] > 2);
                    comps.pb({u});
                    while (comps.back().back() != v) {
                        comps.back().eb(stk.back());
                        stk.pop_back();
                    }
                }
            } else
                low[u] = min(low[u], tin[v]);
        }
    }

    void debug() {
        dbg(n);
        dbg(id);
        dbg(isGraphCutpoint);
        dbg(isTreeCutpoint);
        dbg(tin);
        dbg(low);
        dbg(stk);
        dbg(comps);
        dbg(tree);
    }

    int countMandatoryNodesOnPath(int startNode, int endNode) {
        startNode = idOnTree[startNode], endNode = idOnTree[endNode];

        int ans = !isTreeCutpoint[startNode] + !isTreeCutpoint[endNode];

        int artPoints = 0;
        function<void(int, int)> dfsCount = [&](int u, int p) {
            artPoints += isTreeCutpoint[u];

            if (u == endNode) ans += artPoints;

            for (auto v : treeAdj[u]) {
                if (v != p) {
                    dfsCount(v, u);
                }
            }

            artPoints -= isTreeCutpoint[u];
        };

        dfsCount(startNode, -1);

        return ans;
    }
};

