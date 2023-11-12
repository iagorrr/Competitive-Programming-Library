const int MAXN(2000), MAXM(2000);
ll memo[MAXN][MAXM + 1];
char choosen[MAXN][MAXM + 1];
ll knapSack(int u, int w, vll &VS, vi &WS) {
  if (u < 0) return 0;
  if (memo[u][w] != -1) return memo[u][w];

  ll a = 0, b = 0;
  a = knapSack(u - 1, w, VS, WS);
  if (WS[u] <= w)
    b = knapSack(u - 1, w - WS[u], VS, WS) + VS[u];
  if (b > a) {
    choosen[u][w] = true;
  }
  return memo[u][w] = max(a, b);
}
pair<ll, vi> knapSack(int W, vll &VS, vi &WS) {
  memset(memo, -1, sizeof(memo));
  memset(choosen, 0, sizeof(choosen));
  int n = len(VS);
  ll v = knapSack(n - 1, W, VS, WS);
  ll cw = W;
  vi choosed;
  for (int i = n - 1; i >= 0; i--) {
    if (choosen[i][cw]) {
      cw -= WS[i];
      choosed.emplace_back(i);
    }
  }
  return {v, choosed};
}
