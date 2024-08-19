/*8<
  @Title:

    Knapsack

  @Description:

    Finds the maximum score you can achieve,
    given that you have $N$ items, each item has
    a $cost$, a $point$ and a $quantity$, you can
    spent at most $maxcost$ and buy each item the
    maximum quantity it has.

  @Time:

    $O(n \cdot maxcost \cdot \log{maxqtd})$

  @Memory:

    $O(maxcost)$.

>8*/

ll knapsack(const vi &weight, const vll &value,
            const vi &qtd, int maxCost) {
  vi costs;
  vll values;
  for (int i = 0; i < len(weight); i++) {
    ll q = qtd[i];
    for (ll x = 1; x <= q; q -= x, x <<= 1) {
      costs.eb(x * weight[i]);
      values.eb(x * value[i]);
    }
    if (q) {
      costs.eb(q * weight[i]);
      values.eb(q * value[i]);
    }
  }

  vll dp(maxCost + 1);
  for (int i = 0; i < len(values); i++) {
    for (int j = maxCost; j > 0; j--) {
      if (j >= costs[i])
        dp[j] = max(dp[j],
                    values[i] + dp[j - costs[i]]);
    }
  }
  return dp[maxCost];
}
