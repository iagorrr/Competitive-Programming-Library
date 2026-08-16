/*8<
  @Title:
    Lazy Segment Tree (bottom-up, monoid)

  @Description:
    Range update and range query segment tree.

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

    Restrictions:
    \begin{compactitem}
      \item ch must distribute over op: $ch(op(a,b),x) = op(ch(a,x), ch(b,x))$
      \item cmp must follow: $ch(a, cmp(x,y)) = ch(ch(a,x), y)$
    \end{compactitem}

  @Usage:
    vector<S::T> v(n);
    LazySeg<S> seg(v);
    seg.update(lazy, l, r); // range update [l, r] (0-indexed)
    seg.query(l, r);        // range query  [l, r] (0-indexed)

  @Time:
    Build $O(N)$, update/query $O(\log N)$
>8*/

#pragma once
#include "../../Contest/template.cpp"

#define V vector
#define UT(s, x) using x = typename s::x

template <class S>
struct LazySeg {
    UT(S, T);
    UT(S, L);
    signed n, h;
    V<T> seg;
    V<L> lz;
    V<bool> ig;
    V<signed> lx, rx;

    LazySeg(V<T> v)
        : n(int(v.size())),
          seg(2 * n, S::id),
          lz(n),
          ig(n, 1),
          lx(2 * n),
          rx(2 * n) {
        h = 1 + __builtin_clz(1) - __builtin_clz(n);
        for (int i = 0; i < n; i++)
            seg[i + n] = v[i], lx[i + n] = rx[i + n] = i;
        for (int i = n - 1; i >= 0; i--)
            calc(i), lx[i] = lx[2 * i], rx[i] = rx[2 * i + 1];
    }

    void calc(int i) { seg[i] = S::op(seg[2 * i], seg[2 * i + 1]); }
    void ch(L v, int i) { seg[i] = S::ch(seg[i], v, lx[i], rx[i]); }
    void fix(int p) { ig[p] ? calc(p) : ch(lz[p], p); }

    void apply(L v, int p) {
        ch(v, p);
        if (p < n) lz[p] = ig[p] ? v : S::cmp(lz[p], v), ig[p] = 0;
    }

    void push(int p) {
        for (int k = h; k; k--) {
            int i = (p + n) >> k;
            if (ig[i]) continue;
            apply(lz[i], 2 * i);
            apply(lz[i], 2 * i + 1);
            ig[i] = 1;
        }
    }

    void update(L v, int l, int r) {
        push(l);
        push(r);
        int cl = 0, cr = 0;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (cl) fix(l - 1);
            if (cr) fix(r);
            if (l & 1) apply(v, l++), cl = 1;
            if (r & 1) apply(v, --r), cr = 1;
        }
        for (l--; r; l /= 2, r /= 2) {
            if (cl) fix(l);
            if (cr and ((not cl) or (l != r))) fix(r);
        }
    }

    T query(int l, int r) {
        push(l);
        push(r);
        T vl = S::id, vr = S::id;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) vl = S::op(vl, seg[l++]);
            if (r & 1) vr = S::op(seg[--r], vr);
        }
        return S::op(vl, vr);
    }
};
