/*8<
  @Title:
    Increment update, sum query

  @Description:
    Adds $x$ to all elements in $[l, r]$ and
    queries the sum of elements in $[l, r]$.

    Each leaf is initialized as $\{a_i, 1\}$.
    The query returns a pair where \textbf{.fi}
    is the sum and \textbf{.se} is the count.

  @Usage:
    vector<pll> v(n);
    for (int i = 0; i < n; i++) v[i] = {a[i], 1};
    LazySeg<IncrSumS> seg(v);
    seg.update(x, l, r);       // add x to [l,r]
    seg.query(l, r).fi;        // sum of [l,r]

>8*/

#pragma once
#include "../../Contest/template.cpp"
#include "Struct.cpp"

struct IncrSumS {
    using T = pll;  // {sum, count}
    using L = ll;
    static constexpr T id = {0LL, 0LL};
    static T op(T a, T b) { return {a.fi + b.fi, a.se + b.se}; }
    static T ch(T t, L upd, int lx, int rx) {
        return {t.fi + t.se * upd, t.se};
    }
    static L cmp(L cur, L upd) { return cur + upd; }
};

using IncrSumSeg = LazySeg<IncrSumS>;
