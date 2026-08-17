#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../../Contest/template.cpp"
#include "./struct.cpp"

struct S {
    using T = ll;
    static constexpr T id = 0;
    static T op(T a, T b) { return a + b; }
};

signed main() {
    fastio;
    int n, q;
    cin >> n >> q;
    vll a(n);
    cin >> a;
    SegTree<S> seg(a);
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int p;
            ll x;
            cin >> p >> x;
            seg.update(seg.query(p, p) + x, p);
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.query(l, r - 1) << endl;
        }
    }
}
