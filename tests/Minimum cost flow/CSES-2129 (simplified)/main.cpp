#include "../../../content/Contest/template.cpp"
#include "../../../content/Graphs/Minimum cost flow.cpp"

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;

  int source = 2 * N;
  int sink = source + 1;
  MinCostFlow<ll> mcmf(2 * N + 1 + 1, source,
                       sink);

  rep(i, 0, N) {
    mcmf.addEdge(source, i, 1, 0);
    mcmf.addEdge(i + N, sink, 1, 0);
    rep(j, 0, N) {
      int cij;
      cin >> cij;
      mcmf.addEdge(i, N + j, 1, cij);
    }
  }

  auto [flow, cost] = mcmf.flow();
  cout << cost << endl;
}
