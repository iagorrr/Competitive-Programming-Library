/*8<
  @Title: Linear Recurrence
  @Description:
    Find the n-th term of a linear recurrence,
    given the recurrence $rec$ and the first $K$
    values of the recurrence, remember that
    first\_k[i] is the value of $f(i)$,
    considering 0-indexing.
  @Usage:
    Suppose you want the N-th term of Fibonacci
    the first $k$ should be {1,1}, and the rec
    should be {{0,1},{1,1}}.
  @Time: $O(K^{3} \log{N})$
>8*/
template <typename T>
vector<vector<T>> prod(vector<vector<T>> &a, vector<vector<T>> &b,
                       const ll mod) {
    assert(a.back().size() == b.size());
    int n = a.size();
    int m = a.back().size();
    vector<vector<T>> c(n, vector<T>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                c[i][j] = (c[i][j] + ((a[i][k] * b[k][j]) % mod)) % mod;
            }
        }
    }

    return c;
}

template <typename T>
vector<vector<T>> fpow(vector<vector<T>> &xs, ll p, ll mod) {
    vector<vector<T>> ans(xs.size(), vector<T>(xs.size()));
    for (int i = 0; i < (int)xs.size(); i++) ans[i][i] = 1;

    for (auto b = xs; p; p >>= 1, b = prod(b, b, mod))
        if (p & 1) ans = prod(ans, b, mod);

    return ans;
}

ll linear_req(vector<vector<ll>> rec, vector<ll> first_k, ll n, const ll mod) {
    int k = first_k.size();
    if (n <= k) return first_k[n - 1];
    ll n2 = n - k;
    rec = fpow(rec, n2, mod);
    ll ret = 0;
    for (int i = 0; i < k; i++)
        ret = (ret + (rec.back()[i] * first_k[i]) % mod) % mod;
    return ret;
}
