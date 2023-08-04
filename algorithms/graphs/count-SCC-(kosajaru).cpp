void dfs(ll u, vchar &visited, const vll2d &g, vll &scc, bool buildScc) {
        visited[u] = true;
        for (auto &v : g[u])
                if (!visited[v]) dfs(v, visited, g, scc, buildScc);

        // if it's the first pass, add the node to the scc
        if (buildScc) scc.eb(u);
}

ll kosajaru(vll2d &g) {
        ll n = len(g);
        vll scc;
        vchar vis(n);
        for (ll i = 0; i < n; i++)
                if (!vis[i]) dfs(i, vis, g, scc, true);

        // build the transposed graph
        vll2d gt(n);
        for (int i = 0; i < n; ++i)
                for (auto &v : g[i]) gt[v].eb(i);

        // run the dfs on the previous scc order
        ll scccnt = 0;
        vis.assign(n, false);
        for (ll i = len(scc) - 1; i >= 0; i--)
                if (!vis[scc[i]]) dfs(scc[i], vis, gt, scc, false), scccnt++;
        return scccnt;
}
