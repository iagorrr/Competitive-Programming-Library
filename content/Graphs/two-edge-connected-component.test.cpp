#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"
#include "../Contest/template.cpp"
#include "./two-edge-connected-component.cpp"

signed main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b, i);
        g[b].eb(a, i);
    }
    TwoEdgeCC tcc(g);
    vector<vector<int>> comps(tcc.qtdComps);
    rep(i, n) comps[tcc.compId[i]].pb(i);
    cout << tcc.qtdComps << endl;
    for (auto &v : comps) {
        cout << len(v);
        for (int x : v) cout << ' ' << x;
        cout << endl;
    }
}
