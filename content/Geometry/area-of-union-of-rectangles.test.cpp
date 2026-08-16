#define PROBLEM "https://judge.yosupo.jp/problem/area_of_union_of_rectangles"
#include "./area-of-union-of-rectangles.cpp"

signed main() {
    fastio;
    int n;
    cin >> n;

    vector<pair<Point<int>, Point<int>>> pts;
    rep(n) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Point p1(x1, y1);
        Point p2(x2, y2);
        pts.pb({p1, p2});
    }
    cout << areaOfRectanglesUnion(pts) << endl;
}
