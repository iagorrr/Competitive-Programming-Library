using vi = vector<int>;
vector<vi> dist;
vector<vi> memo;
/* O ( N^2 * 2^N )*/
int tsp(int i, int mask, int N)
{
  if (mask == (1 << N) - 1)
    return dist[i][0];
  if (memo[i][mask] != -1)
    return memo[i][mask];
  int ans = INT_MAX << 1;
  for (int j = 0; j < N; ++j)
  {
    if (mask & (1 << j))
      continue;
    auto t = tsp(j, mask | (1 << j), N) + dist[i][j];
    ans = min(ans, t);
  }
  return memo[i][mask] = ans;
}
