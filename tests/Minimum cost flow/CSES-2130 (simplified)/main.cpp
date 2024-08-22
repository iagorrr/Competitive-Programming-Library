#include "../../../content/Contest/template.cpp"
#include "../../../content/Graphs/Minimum cost flow.cpp"

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N, M, K;
  cin >> N >> M >> K;

  int source = 0, sink = N - 1;
  MinCostFlow<ll> st(N, source, sink);
  rep(i, 0, M) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    st.addEdge(a, b, 1, 1);
  }

  auto [flow, cost] = st.flow(K);

  if (flow != K) {
    cout << -1 << endl;
    return 0;
  }

  cout << cost << endl;
}
