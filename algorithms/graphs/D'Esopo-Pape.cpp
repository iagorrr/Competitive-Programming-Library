/*~======================== BEGIN D´ESOPO-PAPE =========================~*/

using Edge = pair<ll, int>;
using Adj = vector<vector<Edge>>;

pair<vll,vi> desopo_pape(int s, int n, const Adj& adj) {
        vll ds(n, LLONG_MAX), ps(n, -1);
        ds[s] = 0;
        vi ms(n, 2);
        deque<int> q;
        q.eb(s);
        while (len(q)) {
                int u = q.front();
                q.pop_front();
                ms[u] = 0;
                for (auto [w, v] : adj[u]) {
                        if (chmin(ds[v], w + ds[u])) {
                                ps[v] = u;
                                if (ms[v] == 2) 
                                        ms[v] = 1, q.pb(v);
                                else if (ms[v] == 0) 
                                        ms[v] = 1, q.pf(v);
                        }
                }
        }
        return {ds, ps};
}

/*~========================= END D´ESOPO-PAPE ==========================~*/
