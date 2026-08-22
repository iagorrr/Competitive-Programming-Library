#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "./dijkstra.cpp"

#include "../Contest/template.cpp"

signed main() {
    fastio;
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<pair<ll, int>>> g(n);
    rep(m) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        g[a].eb(c, b);
    }

    auto [ds, ps] = dijkstra(g, s);

    if (ds[t] == LLONG_MAX) {
        cout << -1 << endl;
        return 0;
    }

    auto path = recover_path(s, t, ps);
    if (path.empty()) path = {s};  // s == t: 0 edges

    cout << ds[t] << ' ' << len(path) - 1 << endl;
    rep(i, 1, len(path)) cout << path[i - 1] << ' ' << path[i] << endl;
}
