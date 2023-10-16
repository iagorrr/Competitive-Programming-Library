template <typename T>
// Query is of the form {L, R, K}
vector<T> count_greater_k(const vector<T> &v, const vector<tuple<int, int, T>> &q) {
  struct Node {
    int pos, value, l, r;
  };

  int n = (int)v.size();
  int m = (int)q.size();
  vector<Node> a(n+m);
  for (int i = 0; i < n; i++) {
    a[i].pos = a[i].l = -1;
    a[i].r = i;
    a[i].value = v[i];
  }

  for (int j = 0; j < m; j++) {
    int i = j+n;
    auto [l, r, k] = q[j];
    a[i].pos = j;
    a[i].l = l;
    a[i].r = r;
    a[i].value = k;
  }

  sort(all(a), [](auto x, auto y) {
    if (x.value == y.value)
      return x.l > y.l;
    return x.value > y.value;
  });

  vector<int> ans(m);

  BITree<int> bit(n+m);
  for (int i = 0; i < n+m; i++) {
    if (a[i].pos != -1) {
      ans[a[i].pos] = bit.range_sum(a[i].l, a[i].r);
    } else {
      bit.update(a[i].r, 1);
    }
  }

  return ans;
}
