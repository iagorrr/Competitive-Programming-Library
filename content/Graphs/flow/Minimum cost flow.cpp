/*8<

  @Title: Minimum Cost Flow

  @Description:

    Given a network find the minimum cost to
    achieve a flow of at most $f$. Works with
    \textbf{directed} and \textbf{undirected}
    graphs

  @Usage:

    \begin{compactitem}
      \item \textbf{add(u, v, c, w):} adds an
      edge from $u$ to $v$ with capacity $c$
      and cost $w$.

      \item \textbf{flow(f):} return a pair
      $(flow, cost)$ with the maximum flow
      until $f$ with source at $s$ and sink at
      $t$, with the minimum cost possible.
    \end{compactitem}

  @Time:

    $O(N \cdot M + f \cdot m \log{n})$
>8*/

template <typename T>
struct MinCostFlow {
    struct Edge {
        int to;
        ll c, rc;  // capcity, residual capacity
        T w;       // cost
    };
    int n, s, t;
    vector<Edge> edges;
    vi2d g;
    vector<T> dist;
    vi pre;

    MinCostFlow() {}
    MinCostFlow(int n_, int _s, int _t) : n(n_), s(_s), t(_t), g(n) {}

    void addEdge(int u, int v, ll c, T w) {
        g[u].pb(len(edges));
        edges.eb(v, c, 0, w);
        g[v].pb(len(edges));
        edges.eb(u, 0, 0, -w);
    }

    // {flow, cost}
    pair<ll, T> flow(ll flow_limit = LLONG_MAX) {
        ll flow = 0;
        T cost = 0;
        while (flow < flow_limit and dijkstra(s, t)) {
            ll aug = LLONG_MAX;
            for (int i = t; i != s; i = edges[pre[i] ^ 1].to) {
                aug = min({flow_limit - flow, aug, edges[pre[i]].c});
            }
            for (int i = t; i != s; i = edges[pre[i] ^ 1].to) {
                edges[pre[i]].c -= aug;
                edges[pre[i] ^ 1].c += aug;

                edges[pre[i]].rc += aug;
                edges[pre[i] ^ 1].rc -= aug;
            }
            flow += aug;
            cost += (T)aug * dist[t];
        }
        return {flow, cost};
    }

    // Needs to be called after flow method
    vi2d paths() {
        vi2d p;
        for (;;) {
            int cur = s;
            auto &res = p.eb();
            res.pb(cur);
            while (cur != t) {
                bool found = false;
                for (auto i : g[cur]) {
                    auto &[v, _, c, cost] = edges[i];
                    if (c > 0) {
                        --c;
                        res.pb(cur = v);
                        found = true;
                        break;
                    }
                }

                if (!found) break;
            }

            if (cur != t) {
                p.ppb();
                break;
            }
        }

        return p;
    }

   private:
    bool bellman_ford(int s, int t) {
        dist.assign(n, numeric_limits<T>::max());
        pre.assign(n, -1);

        vc inq(n, false);
        queue<int> q;

        dist[s] = 0;
        q.push(s);

        while (len(q)) {
            int u = q.front();
            q.pop();
            inq[u] = false;

            for (int i : g[u]) {
                auto [v, c, w, _] = edges[i];
                auto new_dist = dist[u] + w;
                if (c > 0 and dist[v] > new_dist) {
                    dist[v] = new_dist;
                    pre[v] = i;
                    if (not inq[v]) {
                        inq[v] = true;
                        q.push(v);
                    }
                }
            }
        }

        return dist[t] != numeric_limits<T>::max();
    }

    bool dijkstra(int s, int t) {
        dist.assign(n, numeric_limits<T>::max());
        pre.assign(n, -1);
        dist[s] = 0;

        using PQ = pair<T, int>;
        pqmn<PQ> pq;
        pq.emp(0, s);
        while (len(pq)) {
            auto [cost, u] = pq.top();
            pq.pop();
            if (cost != dist[u]) continue;

            for (int i : g[u]) {
                auto [v, c, _, w] = edges[i];
                auto new_dist = dist[u] + w;
                if (c > 0 and dist[v] > new_dist) {
                    dist[v] = new_dist;
                    pre[v] = i;
                    pq.emp(new_dist, v);
                }
            }
        }

        return dist[t] != numeric_limits<T>::max();
    }
};
