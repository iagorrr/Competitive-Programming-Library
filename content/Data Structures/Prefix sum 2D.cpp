/*8<==========================================>8*/
/*8<
  @Title:

    Prefix Sum 2D

  @Description:

    Given an 2D array with $N$ lines and $M$
    columns, find the sum of the subarray that
    have the left upper corner at $(x1, y1)$ and
    right bottom corner at $(x2, y2)$.

  @Time:

    Build $O(N \cdot M)$, Query $O(1)$.

>8*/

template <typename T>
struct psum2d {
  vector<vector<T>> s;
  vector<vector<T>> psum;
  psum2d(vector<vector<T>> &grid, int n, int m)
      : s(n + 1, vector<T>(m + 1)),
        psum(n + 1, vector<T>(m + 1)) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        s[i][j] =
            s[i][j - 1] + grid[i - 1][j - 1];
        psum[i][j] = psum[i - 1][j] + s[i][j];
      }
  }

  T query(int x1, int y1, int x2, int y2) {
    T ans = psum[x2 + 1][y2 + 1] + psum[x1][y1];
    ans -= psum[x2 + 1][y1] + psum[x1][y2 + 1];
    return ans;
  }
};
