#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include "../Contest/template.cpp"
#include "./NTT convolution and exponentiation.cpp"

signed main() {
    fastio;
    int n, m;
    cin >> n >> m;

    vector<mint<998244353>> a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];

    auto c = convolution<998244353>(a, b);
    c.resize(n + m - 1);
    rep(i, 0, len(c)) cout << c[i] << " \n"[i + 1 == len(c)];
}
