#include "../../../content/Contest/template.cpp"

void run();

int32_t main() {
#ifndef LOCAL
    fastio;
#endif

    int T = 1;

    // cin >> T;

    rep(t, 0, T) {
        dbg(t);
        run();
    }
}

/**
 * Author: Lucian Bicsi
 * Date: 2017-10-31
 * License: CC0
 * Source: Wikipedia
 * Description: Recovers any $n$-order linear recurrence relation from the first
 * $2n$ terms of the recurrence.
 * Useful for guessing linear recurrences after brute-forcing the first terms.
 * Should work on any field, but numerical stability for floats is not
 * guaranteed. Output will have size $\le n$. Usage: berlekampMassey({0, 1, 1,
 * 3, 5, 11}) // {1, 2} Time: O(N^2) Status: bruteforce-tested mod 5 for n <= 5
 * and all s
 */

const ll mod = 998244353;  // faster if const

ll modpow(ll b, ll e) {
    ll ans = 1;
    for (; e; b = b * b % mod, e /= 2)
        if (e & 1) ans = ans * b % mod;
    return ans;
}

vector<ll> berlekampMassey(vector<ll> s) {
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
    for (ll& x : C) x = (mod - x) % mod;
    return C;
}

void run() {
    int N;
    cin >> N;
    vll AS(N);
    trav(ai, AS) cin >> ai;
    auto ans = berlekampMassey(AS);
    cout << len(ans) << endl;
    trav(ai, ans) cout << ai << ' ';
    cout << endl;
}

/*8<
>8*/
