/*8<
  @Title:
    Lazy Sparse Segment Tree

  @Description:
    Range update and range query over large or
    uncompressed index spaces (up to $10^{18}$).

    $S$ must satisfy:
    \begin{compactitem}
      \item \textbf{T}: query value type
      \item \textbf{L}: lazy value type
      \item \textbf{id}: identity element of $T$
      \item \textbf{op(a, b)}: associative merge of two $T$ values
      \item \textbf{ch(t, l, lx, rx)}: apply lazy $l$ to node $t$ covering $[lx,
rx]$
      \item \textbf{cmp(a, b)}: compose lazies: apply $a$ then $b$
    \end{compactitem}

    Node 0 is a blank/null node (value $= id$); all nodes
    have both or none of their children.
    \texttt{MXN} should be at least
    $\textit{queries} \cdot \log(n) \cdot 2$.

  @Usage:
    LazySparseSeg<I, S> seg(n);  // indices in [0, n-1]
    seg.update(lazy, l, r);      // range update [l, r]
    seg.query(l, r);             // range query  [l, r]

  @Time:
    Build $O(1)$, update/query $O(\log N)$

  @Warning:
    Implementation comes from arthur9548 personal library, so it has the
    potential to be extremely good !
>8*/

#pragma once
#include "../../Contest/template.cpp"

#define GET(a, x) a = x.a
#define UT(s, x) using x = typename s::x
#define midpoint(l, r) (l + (r - l) / 2)

const int MXN = 1e8;

template <class I, class S>
struct LazySparseSeg {
    using P = int;
    UT(S, T);
    UT(S, L);
    struct Node {
        P lc, rc;
        T val;
        L lz;
        bool ig;
    };
    I n;
    vector<Node> v;
    P new_node() { return v.eb(0, 0, S::id, L(), 1), len(v) - 1; }
    LazySparseSeg(I s) : n(s) {
        v.reserve(MXN);
        new_node();  // blank node (index 0, value = id)
        new_node();  // root node  (index 1)
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
        P GET(lc, v[i]), GET(rc, v[i]);  // copy before potential realloc
        update(x, l, r, lc, lx, mx);
        update(x, l, r, rc, mx + 1, rx);
        v[i].val = S::op(v[lc].val, v[rc].val);
    }
    T query(I l, I r) { return query(l, r, 1, 0, n - 1); }
    T query(I l, I r, P i, I lx, I rx) {
        if (lx > r or rx < l) return S::id;
        prop(i, lx, rx);
        if (l <= lx and rx <= r) return v[i].val;
        I mx = midpoint(lx, rx);
        return S::op(query(l, r, v[i].lc, lx, mx),
                     query(l, r, v[i].rc, mx + 1, rx));
    }
};
