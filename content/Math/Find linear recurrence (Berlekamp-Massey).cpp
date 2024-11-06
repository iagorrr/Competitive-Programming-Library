/*8<
    @Title:
      Find linear recurrence (Berlekamp-Massey)
    @Description:
        Given the first $N$ terms of a linear
        recurrence finds the smallest recurrence
        that matches the sequence.
    @Time: $O(N^2)$
    @Warning:
        Works faster if the $mod$ is const but
        can be also be a parameter.

        Absolute magic !
>8*/
const ll mod = 998244353;

ll modpow(ll b, ll e) {
    ll ans = 1;
    for (; e; b = b * b % mod, e /= 2)
        if (e & 1) ans = ans * b % mod;
    return ans;
}

vl berlekampMassey(vll s) {
    int n = len(s), L = 0, m = 0;
    if (!n) return {};
    vll C(n), B(n), T;
    C[0] = B[0] = 1;

    ll b = 1;
    rep(i, 0, n) {
        ++m;
        ll d = s[i] % mod;
        rep(j, 1, L + 1) d = (d + C[j] * s[i - j]) % mod;
        if (!d) continue;
        T = C;
        ll coef = d * modpow(b, mod - 2) % mod;
        rep(j, m, n) C[j] = (C[j] - coef * B[j - m]) % mod;
        if (2 * L > i) continue;
        L = i + 1 - L;
        B = T;
        b = d;
        m = 0;
    }

    C.resize(L + 1);
    C.erase(C.begin());
    for (ll &x : C) x = (mod - x) % mod;
    return C;
}
