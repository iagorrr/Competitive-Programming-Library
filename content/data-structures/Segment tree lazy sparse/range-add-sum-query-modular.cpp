/*8<
  @Title:
    Range add, modular sum query

  @Description:
    Adds $x$ to all elements in $[l, r]$ and
    queries the sum of elements in $[l, r]$
    modulo some prime.

  @Usage:
    LazySparseSeg<ll, ModSumS> seg(n);
    seg.update(x, l, r);   // add x (mod) to [l, r]
    seg.query(l, r);        // sum of [l, r] (mod)

>8*/

#pragma once
#include "../../Contest/template.cpp"
#include "struct.cpp"

struct ModSumS {
    using T = mint;
    using L = mint;
    static constexpr T id = mint(0);
    static T op(T a, T b) { return a + b; }
    static T ch(T past, L upd, ll lx, ll rx) {
        return past + mint(upd) * mint(rx - lx + 1);
    }
    static L cmp(L cur, L upd) { return cur + upd; }
};
