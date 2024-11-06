#include "../../Contest/template.cpp"

template <typename T, auto op>
struct SegmentTree2D {
    int h, w;
    vector<vector<T>> t;

    SegmentTree2D(const vector<vector<T>> &a)
        : h(a.size()), w(a.back().size()), t(h * 4, vector<T>(w * 4)) {
        build_x(1, 0, h - 1, a);
    }

    void build_y(int vx, int lx, int rx, int vy, int ly, int ry,
                 const vector<vector<T>> &a) {
        if (ly == ry) {
            if (lx == rx)
                t[vx][vy] = a[lx][ly];
            else
                t[vx][vy] = op(t[vx * 2][vy], t[vx * 2 + 1][vy]);
        } else {
            int my = (ly + ry) / 2;
            build_y(vx, lx, rx, vy * 2, ly, my, a);
            build_y(vx, lx, rx, vy * 2 + 1, my + 1, ry, a);
            t[vx][vy] = op(t[vx][vy * 2], t[vx][vy * 2 + 1]);
        }
    }

    void build_x(int vx, int lx, int rx, const vector<vector<T>> &a) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            build_x(vx * 2, lx, mx, a);
            build_x(vx * 2 + 1, mx + 1, rx, a);
        }
        build_y(vx, lx, rx, 1, 0, w - 1, a);
    }

    T query_y(int vx, int vy, int tly, int try_, int ly, int ry) {
        if (ly > ry) return 0;
        if (ly == tly && try_ == ry) return t[vx][vy];
        int tmy = (tly + try_) / 2;
        return op(query_y(vx, vy * 2, tly, tmy, ly, min(ry, tmy)),
                  query_y(vx, vy * 2 + 1, tmy + 1, try_, max(ly, tmy + 1), ry));
    }

    T query_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
        if (lx > rx) return 0;
        if (lx == tlx && trx == rx) return query_y(vx, 1, 0, w - 1, ly, ry);
        int tmx = (tlx + trx) / 2;
        return op(
            query_x(vx * 2, tlx, tmx, lx, min(rx, tmx), ly, ry),
            query_x(vx * 2 + 1, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry));
    }

    void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y,
                  int new_val) {
        if (ly == ry) {
            if (lx == rx)
                t[vx][vy] = new_val;
            else
                t[vx][vy] = op(t[vx * 2][vy], t[vx * 2 + 1][vy]);
        } else {
            int my = (ly + ry) / 2;
            if (y <= my)
                update_y(vx, lx, rx, vy * 2, ly, my, x, y, new_val);
            else
                update_y(vx, lx, rx, vy * 2 + 1, my + 1, ry, x, y, new_val);
            t[vx][vy] = op(t[vx][vy * 2], t[vx][vy * 2 + 1]);
        }
    }

    void update_x(int vx, int lx, int rx, int x, int y, T new_val) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            if (x <= mx)
                update_x(vx * 2, lx, mx, x, y, new_val);
            else
                update_x(vx * 2 + 1, mx + 1, rx, x, y, new_val);
        }
        update_y(vx, lx, rx, 1, 0, w - 1, x, y, new_val);
    }

    T query(int lx, int rx, int ly, int ry) {
        return query_x(1, 0, h - 1, lx, rx, ly, ry);
    }
};
