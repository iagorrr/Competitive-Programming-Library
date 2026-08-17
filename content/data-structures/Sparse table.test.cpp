#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../Contest/template.cpp"
#include "./Sparse table.cpp"

signed main() {
    fastio;
    int n, q;
    cin >> n >> q;
    vll a(n);
    cin >> a;
    SparseTable<ll> st(a);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r - 1) << endl;
    }
}
