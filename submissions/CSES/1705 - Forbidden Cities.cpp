#include <bits/stdc++.h>
using namespace std;

struct block_cut_tree {
    int n;
    vector<int> id, is_cutpoint, tin, low, stk;
    vector<vector<int>> comps, tree;
    block_cut_tree(vector<vector<int>> &g) : n(g.size()), id(n), is_cutpoint(n), tin(n), low(n) {
        // build comps
        for (int i = 0; i < n; i++) {
            if (!tin[i]) {
                int timer = 0;
                dfs(i, -1, timer, g);
            }
        }

        int node_id = 0;
        for (int u = 0; u < n; u++) {
            if (is_cutpoint[u]) {
                id[u] = node_id++;
                tree.push_back({});
            }
        }

        for (auto &comp : comps) {
            int node = node_id++;
            tree.push_back({});
            for (int u : comp) {
                if (!is_cutpoint[u]) {
                    id[u] = node;
                } else {
                    tree[node].emplace_back(id[u]);
                    tree[id[u]].emplace_back(node);
                }
            }
        }
    }

    void dfs(int u, int p, int &timer, vector<vector<int>> &g) {
        tin[u] = low[u] = ++timer;
        stk.emplace_back(u);

        for (auto v : g[u]) {
            if (v == p) continue;
            if (!tin[v]) {
                dfs(v, u, timer, g);
                low[u] = min(low[u], low[v]);
                if (low[v] >= tin[u]) {
                    is_cutpoint[u] = (tin[u] > 1 or tin[v] > 2);
                    comps.push_back({u});
                    while (comps.back().back() != v) {
                        comps.back().emplace_back(stk.back());
                        stk.pop_back();
                    }
                }
            } else
                low[u] = min(low[u], tin[v]);
        }
    }
};

struct LCA {
    int n;
    const int maxlog;
    vector<vector<int>> up;
    vector<int> depth;

    LCA(const vector<vector<int>> &tree)
        : n(tree.size()), maxlog(ceil(log2(n))), up(n, vector<int>(maxlog + 1)), depth(n, -1) {
        for (int i = 0; i < n; i++) {
            if (depth[i] == -1) {
                depth[i] = 0;
                dfs(i, -1, tree);
            }
        }
    }

    void dfs(int u, int p, const vector<vector<int>> &tree) {
        if (p != -1) {
            depth[u] = depth[p] + 1;
            up[u][0] = p;
            for (int i = 1; i <= maxlog; i++) {
                up[u][i] = up[up[u][i - 1]][i - 1];
            }
        }
        for (int v : tree[u]) {
            if (v == p) continue;
            dfs(v, u, tree);
        }
    }

    int kth_jump(int u, int k) {
        for (int i = maxlog; i >= 0; i--) {
            if ((1 << i) & k) {
                u = up[u][i];
            }
        }
        return u;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        u = kth_jump(u, diff);
        if (u == v) return u;
        for (int i = maxlog; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

    bool on_path(int u, int v, int s) {
        int uv = lca(u, v), us = lca(u, s), vs = lca(v, s);
        return (uv == s or (us == uv and vs == s) or (vs == uv and us == s));
    }
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    const int LOGMAX = (int)ceil(log2(n));
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    block_cut_tree bct(g);
    LCA lca(bct.tree);

    for (int i = 0; i < q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;
        if (a == c || b == c ||
            (bct.is_cutpoint[c] && lca.on_path(bct.id[a], bct.id[b], bct.id[c]))) {
            std::cout << "NO\n";
        } else {
            cout << "YES" << '\n';
        }
    }
}
