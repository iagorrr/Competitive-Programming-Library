#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"
#include "../Contest/template.cpp"
#include "./Polynomial Taylor Shift.cpp"

signed main() {
    fastio;
    int n;
    ll c;
    cin >> n >> c;
    vll a(n);
    rep(i, 0, n) cin >> a[i];
    auto b = shift(a, c);
    rep(i, 0, n) cout << b[i] << " \n"[i + 1 == n];
}
