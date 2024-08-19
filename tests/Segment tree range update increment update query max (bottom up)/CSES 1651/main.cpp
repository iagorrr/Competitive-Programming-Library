#include "../../../content/Contest/template.cpp"
#include "../../../content/Data Structures/Segment tree range update range query/Increment update query max (bottom up).cpp"

auto run() {
  int n, q;
  cin >> n >> q;
  vector<QueryT> xs(n);
  for (auto& xi : xs) cin >> xi.v;
  LazySegmentTree st(xs);
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
      cout << st.qry(k, k).v << endl;
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
