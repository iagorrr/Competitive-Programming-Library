/*8<
@Title: Ternary search (integer)

@Description: Given a unimodal function $f$ defined
between the integers $l$ and $r$ finds an $x$ such
that f(x) is maximum/minimum.

@Usage: Just pass the range $l$, $r$ of the function
you are interested, the function that receives an integer
and if you want the maximum value use the cmp = greater<ll>(),
otherwise less<ll>().

@Time: $O(\log{r-l+1})$

@Memory: $O(1)$
>8*/
#include "../Contest/template.cpp"

template <auto cmp = greater<ll>()>
ll ternary_search(ll l, ll r, function<ll(ll)> f) {
    static const ll eps = 3;
    while (r - l >= eps) {
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;
        if (cmp(f(m1), f(m2)))
            r = m2;
        else
            l = m1;
    }
    rep(i, l, r + 1) if (cmp(f(i), f(l))) l = i;
    return l;
}
