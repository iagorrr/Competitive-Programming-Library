/*8<
  @Title:

    Binary Knapsack (bottom up)

  @Description:

    Given the points each element have, and it
    repespective cost, computes the maximum points
we can get if we can ignore/choose an element, in
such way that the sum of costs don't exceed the
maximum cost allowed.

  @Time:

    $O(N*W)$

  @Space:

    $O(N*W)$

  @Warning:

    The vectors $VS$ and $WS$ starts at one,
    so it need an empty value at index 0.
>8*/

const int MAXN(1'000), MAXCOST(1'000 * 20);
ll dp[MAXN + 1][MAXCOST + 1];
bool ps[MAXN + 1][MAXCOST + 1];
pair<ll, vi> knapsack(const vll &points, const vi &costs, int maxCost) {
    int n = len(points) - 1;  // ELEMENTS START AT INDEX 1 !

    for (int m = 0; m <= maxCost; m++) {
        dp[0][m] = 0;
    }

    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + (costs[i] == 0) * points[i];
        ps[i][0] = costs[i] == 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int m = 1; m <= maxCost; m++) {
            dp[i][m] = dp[i - 1][m], ps[i][m] = 0;
            int w = costs[i];
            ll v = points[i];

            if (w <= m and dp[i - 1][m - w] + v > dp[i][m]) {
                dp[i][m] = dp[i - 1][m - w] + v, ps[i][m] = 1;
            }
        }
    }

    vi is;
    for (int i = n, m = maxCost; i >= 1; --i) {
        if (ps[i][m]) {
            is.emplace_back(i);
            m -= costs[i];
        }
    }

    return {dp[n][maxCost], is};
}
