#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_B"
#include "../Contest/template.cpp"
#include "./Find Bridges.cpp"

signed main() {
    fastio;
    cin >> N >> M;
    vector<pii> edges(M);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        edges[i] = {a, b};
        G[a].eb(b, i);
        G[b].eb(a, i);
    }

    findBridges();

    vector<pii> res;
    rep(i, M) if (isBridge[i]) {
        auto [a, b] = edges[i];
        if (a > b) swap(a, b);
        res.eb(a, b);
    }
    sort(all(res));
    for (auto [a, b] : res) cout << a << ' ' << b << endl;
}
