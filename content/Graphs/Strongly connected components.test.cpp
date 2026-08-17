#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include "../Contest/template.cpp"
#include "./Strongly connected components.cpp"

signed main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    rep(m) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    SCC scc(adj);
    // scc_id is assigned in reverse topological order (0 = last).
    // Group vertices by scc_id, output in topological order.
    vector<vector<int>> comps(scc.num_sccs);
    rep(i, n) comps[scc.scc_id[i]].pb(i);
    cout << scc.num_sccs << endl;
    rep(c, scc.num_sccs) {
        auto &v = comps[scc.num_sccs - 1 - c];
        cout << len(v);
        for (int x : v) cout << ' ' << x;
        cout << endl;
    }
}
