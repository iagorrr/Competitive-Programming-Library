/*8<
@Title: Area of Rectangles Union

@Description: Computes the total area covered by a union of
rectangles using a sweep-line algorithm and a lazy segment tree
with coordinate compression.

@Usage: Pass a vector of rectangles represented as pairs of
bottom-left and top-right points.

@Time: $O(N \log N)$
>8*/

#include "../Contest/template.cpp"
#include "../data-structures/segment-tree-lazy/struct.cpp"
#include "./Point.cpp"

struct SegTraits {
    // { min_val, min_len}
    using T = pair<ll, ll>;
    using L = ll;
    inline static const T id = {ll(1e9), 0};

    static T op(const T &a, const T &b) {
        if (a.first < b.first) return a;
        if (b.first < a.first) return b;
        return {a.first, a.second + b.second};
    }

    static T ch(const T &t, const L &l, int lx, int rx) {
        if (t.first == ll(1e9)) return t;
        return {t.first + l, t.second};
    }

    static L cmp(const L &a, const L &b) { return a + b; }
};

ll areaOfRectanglesUnion(
    const vector<pair<Point<int>, Point<int>>> &rectangles) {
    if (rectangles.empty()) return 0;

    // Compress Y-coordinates
    vector<int> Y;
    Y.reserve(rectangles.size() * 2);
    for (auto &[p1, p2] : rectangles) {
        assert(p1.x < p2.x && p1.y < p2.y);
        Y.push_back(p1.y);
        Y.push_back(p2.y);
    }
    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());

    int m = (int)Y.size() - 1;
    if (m <= 0) return 0;

    // Initialize segment tree with intervals
    vector<SegTraits::T> init_v(m);
    for (int i = 0; i < m; ++i) {
        init_v[i] = {0, (ll)(Y[i + 1] - Y[i])};
    }
    LazySeg<SegTraits> seg(init_v);

    // Create sweep-line events: {X, Y_start_idx, Y_end_idx, Type (+1/-1)}
    vector<array<int, 4>> sl;
    sl.reserve(rectangles.size() * 2);
    for (auto &[p1, p2] : rectangles) {
        int y1 = lower_bound(Y.begin(), Y.end(), p1.y) - Y.begin();
        int y2 = lower_bound(Y.begin(), Y.end(), p2.y) - Y.begin();
        sl.push_back({p1.x, y1, y2 - 1, 1});
        sl.push_back({p2.x, y1, y2 - 1, -1});
    }
    sort(sl.begin(), sl.end());

    int prevx = sl.front()[0];
    ll ans = 0, total_y = Y.back() - Y.front();

    // Sweep across X-axis and aggregate area
    for (auto &[curx, ys, yf, inc] : sl) {
        auto res = seg.query(0, m - 1);
        ll covered = total_y - (res.first == 0 ? res.second : 0);
        ans += (ll)(curx - prevx) * covered;

        seg.update(inc, ys, yf);
        prevx = curx;
    }

    return ans;
}
