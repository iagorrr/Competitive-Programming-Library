#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
#include "../../Contest/template.cpp"
#include "./Maximum flow (Dinic).cpp"

signed main() {
    fastio;
    int L, R, m;
    cin >> L >> R >> m;
    // nodes: [0, L) left, [L, L+R) right, source = L+R, sink = L+R+1
    int S = L + R, T = L + R + 1;
    Dinic dinic(L + R + 2);
    rep(i, L) dinic.addEdge(S, i, 1);
    rep(i, R) dinic.addEdge(L + i, T, 1);
    vector<pii> es(m);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        es[i] = {a, b};
        dinic.addEdge(a, L + b, 1);
    }
    dinic.maxFlow(S, T);
    // recover matches: left->right edges with flow used (c == 0 forward,
    // originally 1). Edge index in adj[a]: first two are S/T? No, for left
    // node a the first incoming is from S (stored in adj[a] as reverse).
    // Iterate matching edges directly.
    vector<pii> ans;
    rep(a, L) {
        for (auto &e : dinic.adj[a]) {
            // forward edges from a go to right nodes [L, L+R); reverse edge
            // to S has to == S. Matched if capacity consumed (flow()==1).
            if (e.to >= L && e.to < L + R && e.oc == 1 && e.flow() == 1)
                ans.eb(a, e.to - L);
        }
    }
    cout << len(ans) << endl;
    for (auto [a, b] : ans) cout << a << ' ' << b << endl;
}
