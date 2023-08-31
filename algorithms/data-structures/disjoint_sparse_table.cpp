/*
  Disjoint Sparse table implementation.
  Answers queries of any monoid (has identity element and is associative).

  build: O(NlogN)
  query: O(1)
*/

#define F(expr) [](auto a, auto b) { return expr; }
template <typename T> struct DisjointSparseTable
{
  using Operation = T(*)(T, T);
 
  vector<vector<T>> st;
  Operation f;
  T identity;
 
  static constexpr int log2_floor(unsigned long long i) noexcept { return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1; }

  // Lazy loading constructor. Needs to call build!
  DisjointSparseTable(Operation op, const T neutral = T()) : st(), f(op), identity(neutral) {}
 
  DisjointSparseTable(vector<T> v) : DisjointSparseTable(v, F(min(a,b))) { }
 
  DisjointSparseTable(vector<T> v, Operation op, const T neutral = T()) : st(), f(op), identity(neutral)
  {
    build(v);
  }

  void build(vector<T> v)
  {
    st.resize(log2_floor(v.size())+1, vector<T>(1ll << (log2_floor(v.size())+1)));
    v.resize(st[0].size(), identity);
    for (int level = 0; level < (int)st.size(); ++level)
    {
      for (int block = 0; block < (1 << level); ++block)
      {
        const auto l = block << (st.size() - level);
        const auto r = (block + 1) << (st.size() - level);
        const auto m = l + (r - l) / 2;
 
        st[level][m] = v[m];
        for (int i = m + 1; i < r; i++)
          st[level][i] = f(st[level][i-1], v[i]);
        st[level][m-1] = v[m-1];
        for (int i = m-2; i >= l; i--)
          st[level][i] = f(st[level][i+1], v[i]);
      }
    }
  }
 
  T query(int l, int r) const
  {
    if (l > r) return identity;
    if (l == r) return st.back()[l];
 
    const auto k = log2_floor(l^r);
    const auto level = (int)st.size() - 1 - k;
    return f(st[level][l], st[level][r]);
  }
};
