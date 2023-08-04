/*
 * O(n+m)
 * Returns a pair <a, b>
 *      a: number of SCCs
 *      b: vector of size n, where b[i] is the SCC id of node i
 * */
void dfs(ll u, vchar &visited, const vll2d &g, vll &scc, bool buildScc, ll id,
         vll &sccid) {
        visited[u] = true;
        sccid[u] = id;
        for (auto &v : g[u])
                if (!visited[v]) dfs(v, visited, g, scc, buildScc, id, sccid);

        // if it's the first pass, add the node to the scc
        if (buildScc) scc.eb(u);
}

pair<ll, vll> kosajaru(vll2d &g) {
        ll n = len(g);
        vll scc;
        vchar vis(n);
        vll sccid(n);
        for (ll i = 0; i < n; i++)
                if (!vis[i]) dfs(i, vis, g, scc, true, 0, sccid);

        // build the transposed graph
        vll2d gt(n);
        for (int i = 0; i < n; ++i)
                for (auto &v : g[i]) gt[v].eb(i);

        // run the dfs on the previous scc order
        ll id = 1;
        vis.assign(n, false);
        for (ll i = len(scc) - 1; i >= 0; i--)
                if (!vis[scc[i]]) {
                        dfs(scc[i], vis, gt, scc, false, id++, sccid);
                }
        return {id - 1, sccid};
}
