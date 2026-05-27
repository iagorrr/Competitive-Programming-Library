/*8<
  @Title:
    Segment Tree - Minimum Query

  @Description:
    Example of segment tree configured for range
    minimum queries (RMQ). Uses the generic segment
    tree structure with a minimum monoid.

  @Usage:
    const ll oo = 1e9;
    struct S {
        using T = ll;
        static constexpr T id = oo;
        static T op(T a, T b) { return min(a, b); }
    };

    SegTree<S> seg(n);
    seg.update(value, pos);
    ll minimum = seg.query(l, r);

  @Time:
    Build $O(N)$, update $O(\log N)$, query $O(\log N)$
>8*/

const ll oo = 1e9;
struct S {
    using T = pll;
    static constexpr T id = pll{oo, oo};
    static T op(T a, T b) { return min(a, b); }
};

// Usage example:
// SegTree<S> seg(n);
// seg.update({value, index}, pos);
// pll result = seg.query(l, r);
