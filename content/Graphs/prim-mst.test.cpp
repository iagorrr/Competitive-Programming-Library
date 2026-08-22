#define PROBLEM "https://judge.yosupo.jp/problem/minimum_spanning_tree"
#include "../Contest/template.cpp"
#include "./prim-mst.cpp"

signed main() {
    fastio;
    int n, m;
    cin >> n >> m;
    PrimGraph g(n);
    rep(i, m) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        g[a].eb(c, b, i);
        g[b].eb(c, a, i);
    }

    auto [cost, edges] = prim(g);

    cout << cost << '\n';
    rep(i, len(edges)) cout << (i ? " " : "") << edges[i];
    cout << '\n';
}
