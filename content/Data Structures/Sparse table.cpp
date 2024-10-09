template <typename T = ll,
          auto cmp = [](T &src1, T &src2, T &dst) { dst = min(src1, src2); }>
class SparseTable {
 private:
  int sz;
  vi logs;
  vector<vector<T>> st;

 public:
  SparseTable(const vector<T> &v) : sz(len(v)), logs(sz + 1) {
    rep(i, 2, sz + 1) logs[i] = logs[i >> 1] + 1;
    st.resize(logs[sz] + 1, vector<T>(sz));
    rep(i, 0, sz) st[0][i] = v[i];
    for (int k = 1; (1 << k) <= sz; k++) {
      for (int i = 0; i + (1 << k) <= sz; i++) {
        cmp(st[k - 1][i], st[k - 1][i + (1 << (k - 1))], st[k][i]);
      }
    }
  }
  T query(int l, int r) {
    r++;
    const int k = logs[r - l];
    T ret;
    cmp(st[k][l], st[k][r - (1 << k)], ret);
    return ret;
  }
};
