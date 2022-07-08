/*8<
@Title: Find $F(\mod m)$ period

@Description: Finds the size of period of $F(\mod m)$, essentialy find
$p_i^{e_i}$ for the prime factoriaztion in $m$, apply a formula, and takes the
lcm of it all.

@Warning: Be careful with overflows. To improve performance you may usa
pollard rho for prime factoriaztion instead the "naive way" below.

@Time: $O(\sqrt(m))$
>8*/
#include "../Contest/template.cpp"

ll find_fib_mod_m_period(ll m) {
    ll ret = 1;
    for (ll p = 2; p * p <= m; p++) {
        if (m % p) continue;
        ll e, pow;
        for (e = 0, pow = 1; m % p == 0; m /= p, pow *= p, e++);
        ll pp = p == 5 ? 20 : p * p - 1;
        ret = lcm(ret, pow / p * pp);
    }

    if (m != 1) ret = lcm(ret, m == 5 ? 20 : m * m - 1);

    return ret;
}
