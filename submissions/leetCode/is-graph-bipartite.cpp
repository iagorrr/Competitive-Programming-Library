// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
class Solution {
       public:
        bool isBipartite(vector<vector<int>>& graph) {
                using vi = vector<int>;
                const int INF = 1e9;

                int n = graph.size();

                vi vis(n, INF);
                queue<int> q;
                for (int i = 0; i < n; ++i) {
                        if (vis[i] != INF) continue;
                        q.push(i);
                        vis[i] = 0;
                        while (!q.empty()) {
                                auto cur = q.front();
                                q.pop();
                                for (auto& u : graph[cur]) {
                                        if (vis[u] == vis[cur]) return false;
                                        if (vis[u] != INF) continue;
                                        vis[u] = 1 - vis[cur];
                                        q.push(u);
                                }
                        }
                }
                return true;
        }
};
// AC, graphs, bipartite
