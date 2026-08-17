#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "../Contest/template.cpp"
#include "./DSU.cpp"

signed main() {
    fastio;
    int n, q;
    cin >> n >> q;
    DSU dsu(n);
    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0)
            dsu.union_set(u, v);
        else
            cout << dsu.same_set(u, v) << endl;
    }
}
