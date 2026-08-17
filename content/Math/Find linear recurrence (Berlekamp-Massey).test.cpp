#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"
#include "../Contest/template.cpp"
#include "./Find linear recurrence (Berlekamp-Massey).cpp"

signed main() {
    fastio;
    int n;
    cin >> n;
    vll a(n);
    rep(i, 0, n) cin >> a[i];
    auto c = berlekampMassey(a);
    cout << len(c) << endl;
    rep(i, 0, len(c)) cout << c[i] << " \n"[i + 1 == len(c)];
    if (c.empty()) cout << endl;
}
