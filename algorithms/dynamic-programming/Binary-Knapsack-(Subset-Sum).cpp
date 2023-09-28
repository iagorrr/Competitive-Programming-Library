ll knapSack(int u, ll w, vll &VS, vll &WS, vll2d &memo) {
  if (u < 0 or w <= 0) return 0;
  if (memo[u][w] != -1) return memo[u][w];

  ll a = 0, b = 0;
  a = knapSack(u - 1, w, VS, WS, memo);
  if (WS[u] <= w) b = knapSack(u - 1, w - WS[u], VS, WS, memo) + VS[u];
  return memo[u][w] = max(a, b);
}
