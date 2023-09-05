int LIS(const vi& as) {
  const ll oo = 1e18;
  int n = len(as);
  vll lis(n + 1, oo);
  lis[0] = -oo;

  auto ans = 0;

  for (int i = 0; i < n; ++i) {
    auto it = lower_bound(all(lis), as[i]);
    auto pos = (int)(it - lis.begin());

    ans = max(ans, pos);
    lis[pos] = as[i];
  }

  return ans;
}
