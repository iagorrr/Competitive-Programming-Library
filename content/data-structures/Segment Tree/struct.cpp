/*8<
  @Title:
    Segment Tree (Point Update, Range Query)

  @Description:
    Generic bottom-up segment tree implementation supporting
    point updates and range queries for any associative
    operation defined by a monoid structure.

    The monoid $S$ must provide:
    \begin{compactitem}
      \item $T$ - the element type
      \item $id$ - the identity element
      \item $op(a, b)$ - associative binary operation
    \end{compactitem}

  @Usage:
    // Define monoid structure
    struct S {
        using T = int;
        static constexpr T id = 0;  // identity
        static T op(T a, T b) { return a + b; }  // operation
    };

    SegTree<S> seg(n);           // create with size n
    SegTree<S> seg(vector<T>);   // create from vector
    seg.update(x, p);            // set position p to value x
    seg.query(l, r);             // query range [l, r]

  @Time:
    Build $O(N)$, update $O(\log N)$, query $O(\log N)$

  @Memory:
    $O(2N)$
>8*/

template <class S>
struct SegTree {
    using T = typename S::T;
    int n;
    vector<T> seg;
    void calc(int i) { seg[i] = S::op(seg[2 * i], seg[2 * i + 1]); }
    SegTree(vector<T> v) : n(len(v)), seg(2 * n) {
        rep(i, 0, n) seg[i + n] = v[i];
        for (int i = n - 1; i >= 1; i--) calc(i);
    }
    SegTree(int _n) : n(_n), seg(2 * n, S::id) {}
    void update(T x, int p) { for (seg[p += n] = x; p /= 2; calc(p)); }
    T query(int l, int r) {
        T vl = S::id, vr = S::id;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) vl = S::op(vl, seg[l++]);
            if (r & 1) vr = S::op(seg[--r], vr);
        }
        return S::op(vl, vr);
    }
};
