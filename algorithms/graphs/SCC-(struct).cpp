struct SCC {
        ll N;
        vll2d adj, tadj;
        vll todo, comps, comp;
        vector<set<ll>> sccadj;
        vchar vis;
        SCC(ll _N)
                : N(_N), adj(_N), tadj(_N), comp(_N, -1), sccadj(_N), vis(_N) {}

        void add_edge(ll x, ll y) { adj[x].eb(y), tadj[y].eb(x); }

        void dfs(ll x) {
                vis[x] = 1;
                for (auto &y : adj[x])
                        if (!vis[y]) dfs(y);
                todo.pb(x);
        }
        void dfs2(ll x, ll v) {
                comp[x] = v;
                for (auto &y : tadj[x])
                        if (comp[y] == -1) dfs2(y, v);
        }
        void gen() {
                for (ll i = 0; i < N; ++i)
                        if (!vis[i]) dfs(i);
                reverse(all(todo));
                for (auto &x : todo)
                        if (comp[x] == -1) {
                                dfs2(x, x);
                                comps.pb(x);
                        }
        }

        void genSCCGraph() {
                for (ll i = 0; i < N; ++i) {
                        for (auto &j : adj[i]) {
                                if (comp[i] != comp[j]) {
                                        sccadj[comp[i]].insert(comp[j]);
                                }
                        }
                }
        }
};
