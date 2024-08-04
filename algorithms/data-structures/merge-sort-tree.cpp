#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

template <class T>
struct MergeSortTree {
        int n;
        vector<vector<T>> st;
        MergeSortTree(vector<T> &xs)
            : n(sz(xs)), st(n << 1) {
                for (int i = 0; i < n; i++)
                        st[i + n] = vector<T>({xs[i]});

                for (int i = n - 1; i > 0; i--) {
                        st[i].resize(sz(st[i << 1]) +
                                     sz(st[i << 1 | 1]));
                        merge(all(st[i << 1]),
                              all(st[i << 1 | 1]),
                              st[i].begin());
                }
        }
        int count(int i, T a, T b) {
                return upper_bound(all(st[i]), b) -
                       lower_bound(all(st[i]), a);
        }
        int inrange(int l, int r, T a, T b) {
                int ans = 0;

                for (l += n, r += n + 1; l < r;
                     l >>= 1, r >>= 1) {
                        if (l & 1) ans += count(l++, a, b);
                        if (r & 1) ans += count(--r, a, b);
                }

                return ans;
        }
};

