/*
 * O(V)
 * receives a dependency graph
 * if possible:
 *      returns an order to solve all dependencies
 * else:
 *      empty vector
 * */
bool make(ll v, const vector<vll> &depends, vll &order, vector<char> &done,
          vector<char> &doing) {
        doing[v] = true;
        for (auto &u : depends[v]) {
                if (doing[u]) return false;
                if (not done[u])
                        if (not make(u, depends, order, done, doing))
                                return false;
        }
        doing[v] = false;
        done[v] = true;
        order.pb(v);
        return true;
}
vll topologicalSorting(const vector<vll> &adj) {
        ll n = len(adj);
        vll order;
        vector<char> done(n);
        vector<char> doing(n);
        for (int i = 0; i < n; ++i)
                if (not done[i])
                        if (not make(i, adj, order, done, doing)) return {};
        return order;
}
