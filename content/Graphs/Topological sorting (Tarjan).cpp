/*8<
  @Title:

    Topological Sorting (Tarjan)

  @Description:

    Finds a the topological order for the graph,
    if there is no such order it means the graph
    is cyclic, then it returns an empty vector

  @Time:

    $O(V + E)$
>8*/
const int maxn(1 '00' 000);
int n, m;
vi g[maxn];

int not_found = 0, found = 1, processed = 2;
int state[maxn];

bool dfs(int u, vi &order) {
    if (state[u] == processed) return true;
    if (state[u] == found) return false;

    state[u] = found;

    for (auto v : g[u]) {
        if (not dfs(v, order)) return false;
    }

    state[u] = processed;
    order.emplace_back(u);

    return true;
}

vi topo_sort() {
    vi order;
    memset(state, 0, sizeof state);

    for (int u = 0; u < n; u++) {
        if (state[u] == not_found and not dfs(u, order)) return {};
    }

    reverse(all(order));
    return order;
}
