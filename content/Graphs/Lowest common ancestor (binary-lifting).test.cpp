#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "../Contest/template.cpp"
#include "./Lowest common ancestor (binary-lifting).cpp"

signed main() {
    fastio;
    int n, q;
    cin >> n >> q;
    vector<vector<int>> tree(n);
    rep(i, 1, n) {
        int p;
        cin >> p;
        tree[p].pb(i);
        tree[i].pb(p);
    }
    LCA lca(tree);
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << lca.lca(u, v) << endl;
    }
}
