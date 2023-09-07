vll get_subset_sums(int l, int r, vll &a) {
  int len = r - l + 1;
  vll res;

  for (int i = 0; i < (1 << len); i++) {
    ll sum = 0;
    for (int j = 0; j < len; j++) {
      if (i & (1 << j)) {
        sum += a[l + j];
      }
    }
    res.push_back(sum);
  }
  return res;
};

ll count(vll &xs, ll x) {
  int n = len(xs);
  vll left = get_subset_sums(0, n / 2 - 1, xs);
  vll right = get_subset_sums(n / 2, n - 1, xs);
  sort(all(left));
  sort(all(right));
  ll ans = 0;
  for (ll i : left) {
    auto start_index =
      lower_bound(right.begin(), right.end(), x - i) - right.begin();
    auto end_index =
      upper_bound(right.begin(), right.end(), x - i) - right.begin();
    ans += end_index - start_index;
  }
  return ans;
}
