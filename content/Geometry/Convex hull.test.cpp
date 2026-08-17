#define PROBLEM "https://judge.yosupo.jp/problem/static_convex_hull"
#include "../Contest/template.cpp"
#include "./Convex hull.cpp"

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<Point<ll>> pts(n);
        rep(i, 0, n) cin >> pts[i].x >> pts[i].y;
        auto h = convexHull(pts);
        cout << len(h) << endl;
        for (auto& p : h) cout << p.x << ' ' << p.y << endl;
    }
}
