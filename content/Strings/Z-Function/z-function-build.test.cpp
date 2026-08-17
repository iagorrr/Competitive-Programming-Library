#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "../../Contest/template.cpp"
#include "./z-function-build.cpp"

signed main() {
    fastio;
    string s;
    cin >> s;
    int n = len(s);
    vector<int> z = z_function_build(s);
    // The impl uses the convention Z[0] = 0, but the problem
    // requires Z[0] = |S|. Adjust only in the wrapper.
    z[0] = n;
    rep(i, n) cout << z[i] << (i + 1 == n ? '\n' : ' ');
}
