/*8<
  @Title:
    Smallest prime factor + find prime factors

  @Description:
    \textbf{build\_spf(n)}: builds the smallest prime
    factor (SPF) array for $[1, n]$.

    \textbf{prime\_factors(spf, x)}: returns the prime
    factors of $x$ in non-decreasing order using a
    precomputed SPF array.

  @Usage:
    auto spf = build\_spf(n);
    auto fs  = prime\_factors(spf, x); // e.g. 12 -> [2,2,3]

  @Time:
    build\_spf: $O(N\log\log N)$,
    prime\_factors: $O(\log x)$

>8*/

#pragma once
#include "../Contest/template.cpp"

vll build_spf(ll n) {
    vll spf(n + 1);
    rep(i, 2, n + 1) if (!spf[i]) for (ll j = i; j <= n; j += i) if (!spf[j])
        spf[j] = i;
    return spf;
}

vll prime_factors(vll& spf, ll x) {
    vll fs;
    while (x > 1) {
        fs.eb(spf[x]);
        x /= spf[x];
    }
    return fs;
}
