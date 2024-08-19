#include "../../../content/Contest/template.cpp"
#include "../../../content/Graphs/Maximum flow (Dinic).cpp"

int32_t main() {
  int P, R, C;
  cin >> P >> R >> C;

  vi DS(P);
  for (auto& di : DS) cin >> di;

  vi ES(R);
  for (auto& ei : ES) cin >> ei;

  using tipin = tuple<int, int, int>;
  vector<tipin> CS(C);
  for (auto& [ti, ii, ji] : CS) {
    cin >> ii >> ji >> ti;
    ii--, ji--;
  }
  sort(CS.begin(), CS.end());

  int ans = 1'000'000 + 1;
  const int oo = 1'000'000;
  for (int l = 0, r = 1'000'000 + 1; l <= r;) {
    int k = midpoint(l, r);

    Dinic dinic(R + P + 1 + 1);
    int source = R + P, sink = R + P + 1;

    for (auto [ti, pi, ri] : CS) {
      if (ti > k) break;
      dinic.addEdge(ri, pi + R, oo);
    }

    for (int i = 0; i < R; i++)
      dinic.addEdge(source, i, ES[i]);
    int tot = 0;
    for (int i = 0; i < P; i++) {
      dinic.addEdge(R + i, sink, DS[i]);
      tot += DS[i];
    }

    if (dinic.maxFlow(source, sink) == tot) {
      ans = min(ans, k);
      r = k - 1;
    } else
      l = k + 1;
  }

  if (ans == 1'000'000 + 1) ans = -1;

  cout << ans << '\n';
}
