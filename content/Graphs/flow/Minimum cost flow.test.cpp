#define PROBLEM "https://judge.yosupo.jp/problem/assignment"
#include "../../Contest/template.cpp"
#include "./Minimum cost flow.cpp"

signed main() {
    fastio;
    int n;
    cin >> n;
    // nodes: left [0, n), right [n, 2n), source 2n, sink 2n+1
    int S = 2 * n, T = 2 * n + 1;
    const ll SHIFT = 1'000'000'000LL;  // make all costs non-negative
    MinCostFlow<ll> mcf(2 * n + 2, S, T);
    // remember edge id of left->right to recover assignment
    vector<vector<int>> eid(n, vector<int>(n));
    rep(i, n) rep(j, n) {
        ll a;
        cin >> a;
        eid[i][j] = len(mcf.edges);  // forward edge index
        mcf.addEdge(i, n + j, 1, a + SHIFT);
    }
    rep(i, n) mcf.addEdge(S, i, 1, 0);
    rep(j, n) mcf.addEdge(n + j, T, 1, 0);

    auto [f, cost] = mcf.flow();
    ll total = cost - (ll)n * SHIFT;
    cout << total << endl;
    vi p(n);
    rep(i, n) rep(j, n) {
        // forward edge saturated => capacity c == 0
        if (mcf.edges[eid[i][j]].c == 0) p[i] = j;
    }
    rep(i, n) cout << p[i] << " \n"[i + 1 == n];
}
