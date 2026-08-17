#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "../Contest/template.cpp"
#include "./Factorization (Pollard's rho).cpp"

signed main() {
    fastio;
    int q;
    cin >> q;
    while (q--) {
        ll a;
        cin >> a;
        auto f = fact(a);
        sort(all(f));
        cout << len(f);
        for (ll x : f) cout << ' ' << x;
        cout << endl;
    }
}
