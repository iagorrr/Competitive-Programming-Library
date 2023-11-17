const int maxn(1'00'000);
vector<pair<ll, int>> g[maxn];
int n;

ll prim(int s = 0) {
  priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                 greater<pair<ll, int>>>
    pq;
  vector<char> ingraph(maxn);
  ingraph[s] = true;
  int ingraphcnt = 1;
  for (auto &[w, v] : g[s]) pq.emplace(w, v);

  ll mstcost = 0;
  while (ingraphcnt < n) {
    ll w;
    int v;

    do {
      tie(w, v) = pq.top();
      pq.pop();
    } while (not pq.empty() and ingraph[v]);

    mstcost += w, ingraph[v] = true, ingraphcnt++;

    for (auto &[w2, v2] : g[v]) {
      pq.emplace(w2, v2);
    }
  }

  return ingraphcnt == n ? mstcost : oo;
}
