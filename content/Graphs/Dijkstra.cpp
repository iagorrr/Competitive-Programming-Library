const int MAXN = 1'00'000;
const ll MAXW = 1'000'000ll;
constexpr ll OO = MAXW * MAXN + 1;
using Edge = pair<ll, int>;  // { weigth, node}
using Adj = vector<vector<Edge>>;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
pair<vll, vi> dijkstra(const Adj &g, int s) {
    int n = len(g);
    min_heap<Edge> pq;
    vll ds(n, OO);
    vi ps(n, -1);
    pq.emp(0, s);
    ds[s] = 0;
    while (len(pq)) {
        auto [du, u] = pq.top();
        pq.pop();
        if (ds[u] < du) continue;

        for (auto [w, v] : g[u]) {
            ll ndv = du + w;
            if (chmin(ds[v], ndv)) {
                ps[v] = u;
                pq.emp(ndv, v);
            }
        }

        return {ds, ps};
    }

    // optional !
    vi recover_path(int source, int ending, const vi &ps) {
        if (ps[ending] == -1) return {};
        int cur = ending;
        vi ans;
        while (cur != -1) {
            ans.eb(cur);
            cur = ps[cur];
        }
        reverse(all(ans));
        return ans;
    }
