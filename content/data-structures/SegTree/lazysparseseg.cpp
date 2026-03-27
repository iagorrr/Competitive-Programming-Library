/**
        * Title: Lazy Sparse/Implicit/Dynamic Segment Tree
        * Description: sparse range query and range update
        * Complexity:
                - Query: O(log(n) * (op + ch + cmp))
                - Update: O(log(n) * (op + ch + cmp))
                - Build: O(1)
                - Memory: O(2 * qnt_queries * log(n) * (2 * int + T + L + bool))
        * Restrictions:
                - S must be a monoid (T, id, op)
                - I must be an integer type
        * Observations:
                - Node 0 is a "blank" node, the default child of any node
                - All nodes have both or none of their children
                - MXN should be qnt_queries * log(n) * 2
        * Tested at:
                - Salary Queries (CSES)
                - Range Updates and Sums (CSES)
*/

#define GET(a, x) a = x.a
#define UT(s, x) using x = typename s::x
#define midpoint(l, r) (l + (r - l) / 2)
template <class I, class S>  // index type and algebraic structure
struct LazySparseSeg {
    using P = int;  // pointer type
    UT(S, T);
    UT(S, L);  // value and lazy types
    struct Node {
        P lc, rc;
        T val;
        L lz;
        bool ig;
    };
    I n;
    vector<Node> v;
    P new_node() { return v.eb(0, 0, S::id, L(), 1), sz(v) - 1; }
    LazySparseSeg(I s) : n(s) {
        v.reserve(MXN);  // faster node creation
        new_node();      // blank node
        new_node();      // root node
    }
    void make_children(P i) {
        if (!v[i].lc) v[i].lc = new_node(), v[i].rc = new_node();
    }
    void put(L x, P i) {
        v[i].lz = v[i].ig ? x : S::cmp(v[i].lz, x);
        v[i].ig = 0;
    }
    void prop(P i, I lx, I rx) {
        if (v[i].ig) return;
        v[i].ig = 1;
        v[i].val = S::ch(v[i].val, v[i].lz, lx, rx);
        if (lx == rx) return;
        make_children(i);
        put(v[i].lz, v[i].lc);
        put(v[i].lz, v[i].rc);
    }
    void update(L x, I l, I r) { return update(x, l, r, 1, 0, n - 1); }
    void update(L x, I l, I r, P i, I lx, I rx) {
        if (lx > r or rx < l) return prop(i, lx, rx);
        if (l <= lx and rx <= r) return put(x, i), prop(i, lx, rx);
        I mx = midpoint(lx, rx);
        prop(i, lx, rx);
        make_children(i);
        P GET(lc, v[i]), GET(rc, v[i]);
        update(x, l, r, lc, lx, mx);
        update(x, l, r, rc, mx + 1, rx);
        v[i].val = S::op(v[lc].val, v[rc].val);  // blank's value is id
    }
    T query(I l, I r) { return query(l, r, 1, 0, n - 1); }
    T query(I l, I r, P i, I lx, I rx) {
        if (lx > r or rx < l) return S::id;
        prop(i, lx, rx);
        if (l <= lx and rx <= r) return v[i].val;
        I mx = midpoint(lx, rx);
        return S::op(query(l, r, v[i].lc, lx, mx),
                     query(l, r, v[i].rc, mx + 1, rx));
        // for nonexisting nodes, it will (correctly) return id through blank's
        // val
    }
};

struct SetAddSum {
    using T = int;
    using L = pii;  //{0, x} = add x; {1, x} = set x
    static constexpr T id = 0;
    static T op(T a, T b) { return a + b; }
    static T ch(T past, L upd, int lx, int rx) {
        int s = rx - lx + 1;
        auto [t, x] = upd;
        if (t)
            return s * x;
        else
            return past + s * x;
    }
    static L cmp(L cur, L upd) {
        auto [t1, x1] = cur;
        auto [t2, x2] = upd;
        if (t2)
            return upd;
        else
            return {t1, x1 + x2};
    }
};
