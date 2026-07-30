/*8<
  @Title:

    Two edge connected connected components / Bridge-tree

  @Time:

    $O(n + m)$
>8*/
#include "../Contest/template.cpp"

struct TwoEdgeCC {
    int n, qtdComps;
    vector<vector<pair<int, int>>> g;
    vector<vector<pair<int, int>>> tree;
    vector<int> tin, stck, compId;

    TwoEdgeCC(const vector<vector<pair<int, int>>> &_g)
        : n(_g.size()), qtdComps(0), g(_g), tree(n), tin(n, -1), compId(n, -1) {
        stck.reserve(n);

        for (int i = 0; i < n; i++) {
            if (tin[i] == -1) dfs(i);
        }

        for (int i = 0; i < n; i++) {
            int ci = compId[i];
            for (auto [j, id] : g[i]) {
                if (i < j) continue;

                int cj = compId[j];
                if (ci != cj) {
                    tree[ci].emplace_back(cj, id);
                    tree[cj].emplace_back(ci, id);
                }
            }
        }
    }

    int dfs(int u, int p = -1) {
        int low = tin[u] = (int)stck.size();
        stck.emplace_back(u);

        bool multEdge = false;
        for (auto [v, id] : g[u]) {
            if (v == p and !multEdge) {
                multEdge = true;
                continue;
            }
            low = min(low, tin[v] == -1 ? dfs(v, u) : tin[v]);
        }

        if (low == tin[u]) {
            for (int i = tin[u]; i < len(stck); i++) compId[stck[i]] = qtdComps;
            stck.resize(tin[u]);
            qtdComps++;
        }
        return low;
    }
};
