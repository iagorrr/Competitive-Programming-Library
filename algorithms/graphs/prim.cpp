const int MAXN(1'00'000);
int N;
vector<pair<ll, int>> G[MAXN];
ll prim(vi s = vi(1, 0)) {
  priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                 greater<pair<ll, int>>>
    pq;
  vector<char> ingraph(MAXN);
  int ingraphcnt(0);
  for (auto si : s) {
    ingraphcnt++;
    ingraph[si] = true;
    for (auto &[w, v] : G[si]) pq.emplace(w, v);
  }

  ll mstcost = 0;
  while (ingraphcnt < N and !pq.empty()) {
    ll w;
    int v;

    do {
      tie(w, v) = pq.top();
      pq.pop();
    } while (not pq.empty() and ingraph[v]);

    mstcost += w, ingraph[v] = true, ingraphcnt++;

    for (auto &[w2, v2] : G[v]) {
      pq.emplace(w2, v2);
    }
  }

  return ingraphcnt == N ? mstcost : oo;
}
