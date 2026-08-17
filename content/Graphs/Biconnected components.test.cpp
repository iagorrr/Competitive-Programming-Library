#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"
#include "../Contest/template.cpp"
#include "./Biconnected components.cpp"

signed main() {
    fastio;
    int m;
    cin >> n >> m;
    rep(m) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    build_bccs();
    cout << bcc_cnt << endl;
    rep(i, bcc_cnt) {
        cout << len(nodes[i]);
        for (int x : nodes[i]) cout << ' ' << x;
        cout << endl;
    }
}
