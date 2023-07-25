using polynomial = vector<ll>;
int degree(const polynomial &xs) { return xs.size() - 1; }
ll horner_evaluate(const polynomial &xs, ll x) {
        ll ans = 0;
        ll n = degree(xs);
        for (int i = n; i >= 0; --i) {
                ans *= x;
                ans += xs[i];
        }
        return ans;
}
polynomial operator+(const polynomial &a, const polynomial &b) {
        int n = degree(a);
        int m = degree(b);
        polynomial r(max(n, m) + 1, 0);

        for (int i = 0; i <= n; ++i) r[i] += a[i];
        for (int j = 0; j <= m; ++j) r[j] += b[j];
        while (!r.empty() and r.back() == 0) r.pop_back();
        if (r.empty()) r.push_back(0);
        return r;
}
polynomial operator*(const polynomial &p, const polynomial &q) {
        int n = degree(p);
        int m = degree(q);
        polynomial r(n + m + 1, 0);
        for (int i = 0; i <= n; ++i)
                for (int j = 0; j <= m; ++j) r[i + j] += (p[i] * q[j]);
        return r;
}
