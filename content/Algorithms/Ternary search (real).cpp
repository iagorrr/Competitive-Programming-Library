#include "../Contest/template.cpp"
template <auto cmp = greater<ld>()>
ld ternarySearch(ld l, ld r, function<ld(ld)> f, const ld eps = 1e-9) {
    while (r - l >= eps) {
        ld m1 = l + (r - l) / 3;
        ld m2 = r - (r - l) / 3;
        if (cmp(f(m1), f(m2)))
            r = m2;
        else
            l = m1;
    }
    return l;
}
