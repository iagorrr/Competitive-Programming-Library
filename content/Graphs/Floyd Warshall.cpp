/*8<
  @Title:
    Floyd Warshall

  @Description:

    Simply finds the minimal distance for each
    node to every other node.  $ O(V^3) $
>8*/

vector<vll> floyd_warshall(const vector<vll> &adj, ll n) {
  auto dist = adj;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
      }
    }
  }
  return dist;
}
