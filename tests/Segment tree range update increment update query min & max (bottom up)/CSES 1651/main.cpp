#include "../../../content/Contest/template.cpp"
#include "../../../content/Data Structures/Segment tree range update range query/Increment update query min & max (bottom up).cpp"

auto run() {
  int n, q;
  cin >> n >> q;
  LazySegmentTree st(n);
  rep(i, 0, n) {
    int x;
    cin >> x;
    st.set(i, QueryT(x));
  }
  rep(i, 0, q) {
    int o;
    cin >> o;
    if (o & 1) {
      int a, b, u;
      cin >> a >> b >> u;
      a--, b--;
      st.upd(a, b, u);
    } else {
      int k;
      cin >> k;
      k--;
      cout << st.qry(k, k).mx << endl;
    }
  }
}

int32_t main() {
#ifndef LOCAL
  fastio;
#endif

  int T = 1;

  // cin >> T;

  rep(t, 0, T) {
    dbg(t);
    run();
  }
}

/*{
  }*/
