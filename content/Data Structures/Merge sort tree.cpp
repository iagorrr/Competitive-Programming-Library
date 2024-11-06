/*8<{=======~ BEGIN MERGE SORT TREE ~=========>8*/
/*8<
  @Title: Merge sort tree

  @Description:

    Like a segment tree but each node stores
    the ordered subsegment it represents.

  @Usage:

    \begin{compactitem}
      \item \textbf{$inrange(l, r, a, b)$} :
      counts the number of positions $i$, $ l \leq
      i \leq r$ such that $ a
      \leq x_i \leq b$.
    \end{compactitem}

  @Time:

    Build $O(N \log{N}^2)$, inrange $O(\log{N}^2)$

  @Memory: $O(n \log{N})$

>8*/

template <class T>
struct MergeSortTree {
    int n;
    vector<vector<T>> st;
    MergeSortTree(vector<T> &xs) : n(len(xs)), st(n << 1) {
        rep(i, 0, n) st[i + n] = vector<T>({xs[i]});

        rrep(i, n - 1, 0) {
            st[i].resize(len(st[i << 1]) + len(st[i << 1 | 1]));
            merge(all(st[i << 1]), all(st[i << 1 | 1]), st[i].begin());
        }
    }
    int count(int i, T a, T b) {
        return upper_bound(all(st[i]), b) - lower_bound(all(st[i]), a);
    }
    int inrange(int l, int r, T a, T b) {
        int ans = 0;

        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans += count(l++, a, b);
            if (r & 1) ans += count(--r, a, b);
        }

        return ans;
    }
};

/*8<=========~ END MERGE SORT TREE ~=========}>8*/
