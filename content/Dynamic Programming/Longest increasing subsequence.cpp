/*8<
  @Title:

    Longest Increasing Subsequence


  @Description:

    Find the pair $(sz, psx)$ where $sz$ is the
    size of the longest subsequence and $psx$ is
    a vector where $psx_i$ tells the size of the
    longest increase subsequence that ends at
    position $i$. $get_idx$ just tells which
indices could be in the longest increasing
subsequence.

  @Time:

    $O(n\log{n})$
>8*/

template <typename T>
pair<int, vi> lis(const vector<T> &xs, int n) {
    vector<T> dp(n + 1, numeric_limits<T>::max());
    dp[0] = numeric_limits<T>::min();

    int sz = 0;
    vi psx(n);

    rep(i, 0, n) {
        int pos = lower_bound(all(dp), xs[i]) - dp.begin();

        sz = max(sz, pos);

        dp[pos] = xs[i];

        psx[i] = pos;
    }

    return {sz, psx};
}

template <typename T>
vi get_idx(vector<T> xs) {
    int n = xs.size();

    auto [sz1, psx1] = lis(xs, n);

    transform(rall(xs), xs.begin(), [](T x) { return -x; });

    auto [sz2, psx2] = lis(xs, n);

    vi ans;
    rep(i, 0, n) {
        int l = psx1[i];
        int r = psx2[n - i - 1];
        if (l + r - 1 == sz1) ans.eb(i);
    }

    return ans;
}
