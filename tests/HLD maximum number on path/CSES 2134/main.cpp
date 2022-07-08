
#include "../../../content/Contest/template.cpp"
#include "../../../content/Graphs/Heavy-Light Decomposition (point update)/Maximum number on path.cpp"

auto run() {
  int N, Q;
  cin >> N >> Q;

  vector<Node> VS(N);
  rep(i, 0, N) {
    int vi;
    cin >> vi;
    VS[i] = Node(vi);
  }

  vi2d ADJ(N);
  rep(i, 0, N - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;

    ADJ[a].eb(b);
    ADJ[b].eb(a);
  }

  HeavyLightDecomposition hld(ADJ, VS);

  rep(q, 0, Q) {
    int o;
    cin >> o;

    if (o & 1) {
      int s, x;
      cin >> s >> x;
      s--;
      hld.set(s, Node(x));
    } else {
      int a, b;
      cin >> a >> b;
      a--, b--;
      auto res = hld.query_path(a, b);
      cout << res.value << ' ';
    }
  }

  cout << endl;
}

int32_t main() {
#ifndef LOCAL
  fastio;
#endif

  dbg(t);
  run();
}
