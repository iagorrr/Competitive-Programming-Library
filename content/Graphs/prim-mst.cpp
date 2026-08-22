/*8<
  @Title:

    Prim (MST)

  @Description:

    Given an undirected weighted graph, returns the
    total weight of a minimum spanning tree together
    with the indices of the edges that form it. The
    growth starts from the vertices in $srcs$ (node
    $0$ by default). If the graph is disconnected the
    returned cost is $oo$ and the edge list only spans
    the reached component(s).

  @Usage:

    \begin{compactitem}
      \item Build the adjacency; for the edge with
      index $e$ linking $a,b$ with weight $w$:\\
      $g[a].eb(w, b, e);\quad g[b].eb(w, a, e);$
      \item $auto\ [cost, edges] = prim(g);$
    \end{compactitem}

  @Time:

    $O(E \log E)$
>8*/
#pragma once
#include "../Contest/template.cpp"

// g[u] = list of (weight, neighbor, edge_id)
using PrimGraph = vector<vector<tuple<ll, int, int>>>;

pair<ll, vi> prim(const PrimGraph &g, vi srcs = {0}) {
    const ll oo = 1e18;
    int n = len(g), cnt = 0;
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>>
        pq;
    vector<char> in(n);
    vi edges;
    ll cost = 0;

    auto push = [&](int u) {
        in[u] = true, cnt++;
        for (auto &[w, v, id] : g[u])
            if (not in[v]) pq.emplace(w, v, id);
    };

    for (int s : srcs)
        if (not in[s]) push(s);

    while (cnt < n and not pq.empty()) {
        auto [w, v, id] = pq.top();
        pq.pop();
        if (in[v]) continue;  // stale entry: skip WITHOUT counting it
        cost += w, edges.pb(id), push(v);
    }

    return {cnt == n ? cost : oo, edges};
}
