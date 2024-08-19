#include "../../../content/Contest/template.cpp"
#include "../../../content/Graphs/Heavy-Light Decomposition (point update)/Maximum number on path.cpp"

int merged(vector<pii> a, vector<pii> b) {
  dbg(a);
  dbg(b);
  int ret = 0;
  vector<pii> c = a;
  for (auto bi : b) c.pb(bi);

  sort(all(c), [](pii x, pii y) {
    return x.first == y.first
               ? x.second > y.second
               : x.first < y.first;
  });

  auto [l, r] = c.front();
  rep(i, 1, len(c)) {
    auto [l2, r2] = c[i];
    if (l2 > r) {
      l = l2;
      r = r2;
    } else {
      int il = max(l, l2);
      int ir = min(r2, r);
      ret = ret + ir - il + 1;
      r = max(r2, r);
    }
  }

  dbg(ret);
  return ret;
}
auto run() {
  int N, Q;
  cin >> N >> Q;

  vi2d ADJ(N);
  rep(i, 0, N - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    ADJ[u].eb(v);
    ADJ[v].eb(u);
  }

  vector<Node> tmp(N);
  HeavyLightDecomposition hld(ADJ, tmp);

  rep(q, 0, Q) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--, b--, c--, d--;

    int ans = 0;
    ans += merged(hld.disjoint_ranges(a, b),
                  hld.disjoint_ranges(c, d));

    cout << ans << endl;
  }
}

int32_t main() {
#ifndef LOCAL
  fastio;
#endif

  run();
}
