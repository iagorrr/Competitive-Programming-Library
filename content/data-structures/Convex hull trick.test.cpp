#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include "../Contest/template.cpp"
#include "./Convex hull trick.cpp"

signed main() {
    fastio;
    int n, q;
    cin >> n >> q;
    Cht cht;
    // container maintains max; for min insert (-m,-b) and negate eval
    rep(n) {
        ll m, b;
        cin >> m >> b;
        cht.insert_line(-m, -b);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            ll m, b;
            cin >> m >> b;
            cht.insert_line(-m, -b);
        } else {
            ll x;
            cin >> x;
            cout << -cht.eval(x) << endl;
        }
    }
}
