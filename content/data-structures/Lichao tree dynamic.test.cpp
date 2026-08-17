#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"
#include "../Contest/template.cpp"
#include "./Lichao tree dynamic.cpp"

// impl maintains MAX; for min we insert (-a,-b) and negate the query.
// coordinate domain: x in [-1e9, 1e9]
using LC = LiChaoTree<ll, -1000000000LL, 1000000000LL>;

signed main() {
    fastio;
    int n, q;
    cin >> n >> q;
    LC tree;
    rep(n) {
        ll l, r, a, b;
        cin >> l >> r >> a >> b;
        // segment covers x in [l, r), integer x in [l, r-1]
        tree.addSegment(-a, -b, l, r - 1);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            ll l, r, a, b;
            cin >> l >> r >> a >> b;
            tree.addSegment(-a, -b, l, r - 1);
        } else {
            ll p;
            cin >> p;
            ll res = tree.query(p);
            if (res == LC::inf)
                cout << "INFINITY" << endl;
            else
                cout << -res << endl;
        }
    }
}
