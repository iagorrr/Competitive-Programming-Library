/*8<{=============~ BEGIN DSU ~===============>8*/
/*8<
  @Title:

    DSU / UFDS

  @Usage:

    You may discomment the commented parts to
    find online which nodes belong to each
    set, it makes the $union\_set$ method cost
    $O(log^2)$ instead $O(A)$

>8*/

struct DSU {
  vi ps, sz;

  // vector<unordered_set<int>> sts;

  DSU(int N)
      : ps(N + 1),
        sz(N, 1) /*, sts(N) */
  {
    iota(ps.begin(), ps.end(), 0);
    // for (int i = 0; i < N; i++)
    // sts[i].insert(i);
  }
  int find_set(int x) { return ps[x] == x ? x : ps[x] = find_set(ps[x]); }
  int size(int u) { return sz[find_set(u)]; }
  bool same_set(int x, int y) { return find_set(x) == find_set(y); }
  void union_set(int x, int y) {
    if (same_set(x, y)) return;

    int px = find_set(x);
    int py = find_set(y);

    if (sz[px] < sz[py]) swap(px, py);

    ps[py] = px;
    sz[px] += sz[py];
    // sts[px].merge(sts[py]);
  }
};

/*8<===============~ END DSU ~===============}>8*/
