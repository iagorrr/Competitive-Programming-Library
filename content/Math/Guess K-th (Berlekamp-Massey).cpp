/* Berlekamp-Massey algorithm
 *
 * Given the first n terms of a linear recurrence relation, this algorithm
 * finds the shortest linear recurrence relation that generates the given
 * sequence.
 *
 * Note: mod needs to have inverse
 *
 * Time complexity: O(n^2)
 */
template <typename T>
vector<T> berlekamp_massey(const vector<T> &s) {
    vector<T> cur, best;
    int lf, ld;
    for (int i = 0; i < (int)s.size(); i++) {
        T delta = 0;
        for (int j = 0; j < (int)cur.size(); j++)
            delta += s[i - j - 1] * cur[j];
        if (delta == s[i]) continue;
        if (cur.empty()) {
            cur.resize(i + 1);
            lf = i;
            ld = (int)(delta - s[i]).value();
            continue;
        }
        T coef = -(s[i] - delta) / ld;
        vector<T> c(i - lf - 1);
        c.push_back(coef);
        for (auto &x : best) c.push_back(-x * coef);
        if (c.size() < cur.size()) c.resize(cur.size());
        for (int j = 0; j < (int)cur.size(); j++) c[j] += cur[j];
        if (i - lf + (int)best.size() >= (int)cur.size())
            best = cur, lf = i, ld = (int)(delta - s[i]).value();
        cur = c;
    }
    return cur;
}
template <typename T>
T get_kth(const vector<T> &rec, const vector<T> &dp, ll k) {
    int n = (int)rec.size();
    assert(rec.size() <= dp.size());
    // use fft to speed up
    auto mul = [&](const vector<T> &a, const vector<T> &b) {
        vector<T> res(2 * n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) res[i + j] += a[i] * b[j];
        for (int i = 2 * n - 1; i >= n; i--)
            for (int j = 1; j <= n; j++) res[i - j] += res[i] * rec[j - 1];
        res.resize(n);
        return res;
    };
    vector<T> a(n), x(n);
    x[0] = 1;
    if (n != 1)
        a[1] = 1;
    else
        a[0] = rec[0];
    while (k) {
        if (k & 1) x = mul(x, a);
        a = mul(a, a);
        k >>= 1;
    }
    T res = 0;
    for (int i = 0; i < n; i++) res += x[i] * dp[i];
    return res;
}
template <typename T>
T guess_kth_term(const vector<T> &s, ll k) {
    if (k < (int)s.size()) return s[k];
    auto coef = berlekamp_massey(s);
    if (coef.empty()) return 0;
    return get_kth(coef, s, k);
}
