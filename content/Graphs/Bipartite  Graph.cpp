/*8<
    @Title: Bipartite Graph
    @Description:
        Given a  graph, find the 'left' and
        'right' side if is a bipartite graph, if
        is not then a empty vi2d is returned
    @Time: $O(N+M)$
>8*/
vi2d bipartite_graph(vi2d &adj) {
    int n = len(adj);
    vi side(n, -1);
    vi2d ret(2);
    rep(u, 0, n) {
        if (side[u] == -1) {
            queue<int> q;
            q.emp(u);
            side[u] = 0;
            ret[0].eb(u);
            while (len(q)) {
                int u = q.front();
                q.pop();
                for (auto v : adj[u]) {
                    if (side[v] == -1) {
                        side[v] = side[u] ^ 1;
                        ret[side[v]].eb(v);
                        q.push(v);
                    } else if (side[u] == side[v])
                        return {};
                }
            }
        }
    }
    return ret;
}
