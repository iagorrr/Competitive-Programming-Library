/*
 * receives a permutation [0, n-1]
 * returns a vector of cicles
 * for example: [ 1, 0, 3, 4, 2] -> [[0, 1], [2, 3, 4]]
 * */
vector<vll> getPermutationCicles(const vll &ps) {
  ll n = len(ps);
  vector<char> visited(n);
  vector<vll> cicles;
  for (int i = 0; i < n; ++i) {
    if (visited[i]) continue;

    vll cicle;
    ll pos = i;
    while (!visited[pos]) {
      cicle.pb(pos);
      visited[pos] = true;
      pos = ps[pos];
    }

    cicles.push_back(vll(all(cicle)));
  }
  return cicles;
}
