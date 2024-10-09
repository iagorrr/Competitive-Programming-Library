struct DSU {
  V<ii> p;
  V<int> s;
  int sum = 0;
  DSU(int n) : p(n, {-1, -1}), s(n, 1) {}

  int find(int x) {
    if (p[x].ff < 0) return x;
    return find(p[x].ff);
  }

  void join(int x, int y, int w) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    sum += w;
    if (s[x] < s[y]) swap(x, y);
    s[x] += s[y];
    p[y] = mp(x, w);
  }

  int query(int x, int y) {
    int r = 0;
    while (x != y) {
      if (s[x] < s[y])
        r = max(r, p[x].ss), x = p[x].ff;
      else
        r = max(r, p[y].ss), y = p[y].ff;
    }
    return r;
  }
};
