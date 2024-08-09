/*~===== BEGIN EXTRA EDGES TO MAKE DIRECTED GRAPH FULLY CONNECTED ======~*/

struct SCC {
        int n, num_sccs;
        vi2d adj;
        vi scc_id;

        SCC(int _n) : n(_n), num_sccs(0), adj(n), scc_id(n, -1) {}

        SCC(const vi2d& _adj) : SCC(len(_adj)) {
                adj = _adj;
                find_sccs();
        }

        void add_edge(int u, int v) { adj[u].eb(v); }

        void find_sccs() {
                int timer = 1;
                vi tin(n), st;
                st.reserve(n);
                function<int(int)> dfs = [&](int u) -> int {
                        int low = tin[u] = timer++, siz = len(st);
                        st.eb(u);
                        for (int v : adj[u])
                                if (scc_id[v] < 0)
                                        low = min(
                                            low, tin[v] ? tin[v] : dfs(v));
                        if (tin[u] == low) {
                                rep(i, siz, len(st))
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

vector<array<int, 2>> extra_edges(const vi2d& adj) {
        SCC scc(adj);
        auto scc_id = scc.scc_id;
        auto num_sccs = scc.num_sccs;

        if (num_sccs == 1) return {};

        int n = len(adj);
        vi2d scc_adj(num_sccs);
        vi zero_in(num_sccs, 1);
        rep(u, 0, n) {
                for (int v : adj[u]) {
                        if (scc_id[u] == scc_id[v]) continue;
                        scc_adj[scc_id[u]].eb(scc_id[v]);
                        zero_in[scc_id[v]] = 0;
                }
        }

        int random_source = max_element(all(zero_in)) - zero_in.begin();

        vi vis(num_sccs);
        function<int(int)> dfs = [&](int u) {
                if (empty(scc_adj[u])) return u;
                for (int v : scc_adj[u])
                        if (!vis[v]) {
                                vis[v] = 1;
                                int zero_out = dfs(v);
                                if (zero_out != -1) return zero_out;
                        }
                return (int)-1;
        };

        vector<array<int, 2>> edges;
        vi in_unused;
        rep(i, 0, num_sccs) {
                if (zero_in[i]) {
                        vis[i] = 1;
                        int zero_out = dfs(i);
                        if (zero_out != -1)
                                edges.push_back({zero_out, i});
                        else
                                in_unused.push_back(i);
                }
        }

        rep(i, 1, len(edges)) { swap(edges[i][0], edges[i - 1][0]); }

        rep(i, 0, num_sccs) {
                if (scc_adj[i].empty() && !vis[i]) {
                        if (!in_unused.empty()) {
                                edges.push_back({i, in_unused.back()});
                                in_unused.pop_back();
                        } else {
                                edges.push_back({i, random_source});
                        }
                }
        }

        for (int u : in_unused) edges.push_back({0, u});

        vi to_node(num_sccs);
        rep(i, 0, n) to_node[scc_id[i]] = i;
        for (auto& [u, v] : edges) u = to_node[u], v = to_node[v];

        return edges;
}

/*~====== END EXTRA EDGES TO MAKE DIRECTED GRAPH FULLY CONNECTED =======~*/
