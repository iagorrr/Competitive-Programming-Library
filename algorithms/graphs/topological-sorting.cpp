/*
 * O(V)
 * Assumes:
 *      * the given graph is acyclic
 *      * vertices have index [0, n-1]
 * */
void dfs(const vector<vll> &adj, ll s, vector<char> &vis, vll &order) {
        vis[s] = true;
        for (auto &v : adj[s]) {
                if (not vis[v]) dfs(adj, v, vis, order);
        }
        order.pb(s);
}
vll topologicalSorting(const vector<vll> &adj) {
        ll n = len(adj);
        vll order;
        vector<char> visited(n);
        for (int i = 0; i < n; ++i) {
                if (not visited[i]) {
                        dfs(adj, i, visited, order);
                }
        }
        reverse(all(order));
        return order;
}
