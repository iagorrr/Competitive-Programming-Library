/*8<
  @Title:
    Lowest Common Ancestor

  @Description:

    Given two nodes of a tree find their lowest
    common ancestor, or their distance

  @Title:

    Build : $O(V)$, Queries: $O(1)$
>8*/

template <typename T>
struct SparseTable {
  vector<T> v;
  int n;
  static const int b = 30;
  vi mask, t;

  int op(int x, int y) {
    return v[x] < v[y] ? x : y;
  }
  int msb(int x) {
    return __builtin_clz(1) - __builtin_clz(x);
  }
  SparseTable() {}
  SparseTable(const vector<T> &v_)
      : v(v_), n(v.size()), mask(n), t(n) {
    for (int i = 0, at = 0; i < n;
         mask[i++] = at |= 1) {
      at = (at << 1) & ((1 << b) - 1);
      while (at and op(i, i - msb(at & -at)) == i)
        at ^= at & -at;
    }
    for (int i = 0; i < n / b; i++)
      t[i] = b * i + b - 1 -
             msb(mask[b * i + b - 1]);
    for (int j = 1; (1 << j) <= n / b; j++)
      for (int i = 0; i + (1 << j) <= n / b; i++)
        t[n / b * j + i] =
            op(t[n / b * (j - 1) + i],
               t[n / b * (j - 1) + i +
                 (1 << (j - 1))]);
  }
  int small(int r, int sz = b) {
    return r - msb(mask[r] & ((1 << sz) - 1));
  }
  T query(int l, int r) {
    if (r - l + 1 <= b)
      return small(r, r - l + 1);
    int ans = op(small(l + b - 1), small(r));
    int x = l / b + 1, y = r / b - 1;
    if (x <= y) {
      int j = msb(y - x + 1);
      ans =
          op(ans,
             op(t[n / b * j + x],
                t[n / b * j + y - (1 << j) + 1]));
    }
    return ans;
  }
};

struct LCA {
  SparseTable<int> st;
  int n;
  vi v, pos, dep;

  LCA(const vi2d &g, int root)
      : n(len(g)), pos(n) {
    dfs(root, 0, -1, g);
    st = SparseTable<int>(vector<int>(all(dep)));
  }

  void dfs(int i, int d, int p, const vi2d &g) {
    v.eb(len(dep)) = i, pos[i] = len(dep),
    dep.eb(d);
    for (auto j : g[i])
      if (j != p) {
        dfs(j, d + 1, i, g);
        v.eb(len(dep)) = i, dep.eb(d);
      }
  }

  int lca(int a, int b) {
    int l = min(pos[a], pos[b]);
    int r = max(pos[a], pos[b]);
    return v[st.query(l, r)];
  }
  int dist(int a, int b) {
    return dep[pos[a]] + dep[pos[b]] -
           2 * dep[pos[lca(a, b)]];
  }
};
