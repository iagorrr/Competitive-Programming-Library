/*~================BEGIN LONGEST INCREASING SUBSEQUENCE=================~*/
#define len(j) (int)j.size()
#define all(j) j.begin(), j.end()
#define rall(j) j.rbegin(), j.rend()
#define rep(i, a, b) \
        for (common_type_t<decltype(a), decltype(b)> i = a; i < b; i++)

using vi = vector<int>;

template <typename T>
pair<int, vi> lis(const vector<T>& xs, int n) {
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

        // reverse(all(xs));
        transform(rall(xs), xs.begin(), [](T x) { return -x; });
        // for (auto& xi : xs) xi = -xi;

        auto [sz2, psx2] = lis(xs, n);

        vi ans;
        rep(i, 0, n) {
                int l = psx1[i];
                int r = psx2[n - i - 1];
                if (l + r - 1 == sz1) ans.eb(i);
        }

        return ans;
}

/*~=================END LONGEST INCREASING SUBSEQUENCE==================~*/
