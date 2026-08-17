#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include "../Contest/template.cpp"
#include "./Wavelet tree.cpp"

signed main() {
    fastio;
    int n, q;
    cin >> n >> q;
    vi a(n);
    cin >> a;
    WaveletTree<int> wt(a);
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << wt.kth_element(l, r - 1, k) << endl;
    }
}
