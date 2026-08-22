#include "../Contest/template.cpp"

pair<vector<ll>, vector<int>> dijkstra(const vector<vector<pair<ll, int>>> &g,
                                       int s) {
    int n = len(g);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
        pq;
    vector<ll> ds(n, LLONG_MAX);
    vector<int> ps(n, -1);
    pq.emp(0, s);
    ds[s] = 0;
    while (len(pq)) {
        auto [du, u] = pq.top();
        pq.pop();
        if (ds[u] < du) continue;

        for (auto [w, v] : g[u]) {
            ll ndv = du + w;
            if (ndv < ds[v]) {
                ds[v] = ndv;
                ps[v] = u;
                pq.emp(ndv, v);
            }
        }
    }
    return {ds, ps};
}

// optional !
vector<int> recover_path(int source, int ending, const vector<int> &ps) {
    if (ps[ending] == -1) return {};
    int cur = ending;
    vector<int> ans;
    while (cur != -1) {
        ans.emplace_back(cur);
        cur = ps[cur];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
