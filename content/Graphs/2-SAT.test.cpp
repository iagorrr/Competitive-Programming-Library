#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"
#include "../Contest/template.cpp"
#include "./2-SAT.cpp"

signed main() {
    fastio;
    string p, cnf;
    int n, m;
    cin >> p >> cnf >> n >> m;
    TwoSat ts(n);
    rep(m) {
        int a, b, zero;
        cin >> a >> b >> zero;
        // variable i (1-indexed) -> index i-1; negation via ~
        auto lit = [](int x) { return x > 0 ? x - 1 : ~(-x - 1); };
        ts.add_or(lit(a), lit(b));
    }
    if (!ts.solve()) {
        cout << "s UNSATISFIABLE" << endl;
        return 0;
    }
    cout << "s SATISFIABLE" << endl;
    cout << "v";
    rep(i, n) cout << ' ' << (ts.values[i] ? i + 1 : -(i + 1));
    cout << " 0" << endl;
}
