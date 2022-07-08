/*8<
  @Description:

    Receives a permutation [0, n-1] and return
    a vector 2D with each cycle.


>8*/
vll2d getPermutationCicles(const vll &ps) {
    ll n = len(ps);
    vector<char> visited(n);
    vector<vll> cicles;
    rep(i, 0, n) {
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
