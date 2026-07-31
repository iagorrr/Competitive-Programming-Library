/*8<
  @Title:

    Strongly Connected Components (struct)

  @Description:

    Find the connected component for each edge
    (already in a topological order), some
    additional functions are also provided.

  @Time:

    Build: $O(V+E)$
>8*/
#include "../Contest/template.cpp"

struct SCC {
    int n, num_sccs;
    vector<vector<int>> adj;
    vector<int> scc_id;

    SCC(const vector<vector<int>> &_adj)
        : n(_adj.size()), num_sccs(0), adj(_adj), scc_id(n, -1) {
        build();
    }

    void build() {
        int timer = 1;
        vector<int> tin(n), st;
        st.reserve(n);
        function<int(int)> dfs = [&](int u) -> int {
            int low = tin[u] = timer++, siz = st.size();
            st.eb(u);
            for (int v : adj[u])
                if (scc_id[v] < 0) low = min(low, tin[v] ? tin[v] : dfs(v));
            if (tin[u] == low) {
                for (int i = siz; i < (int)st.size(); i++)
                    scc_id[st[i]] = num_sccs;
                st.resize(siz);
                num_sccs++;
            }
            return low;
        };

        for (int i = 0; i < n; i++)
            if (!tin[i]) dfs(i);
    }
};
