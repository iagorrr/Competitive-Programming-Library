/*8<
@Title: Graph Diameter (General Undirected Graph)

@Description:
    Computes the diameter of a connected undirected graph — defined as the
longest shortest path between any pair of nodes — and returns both the diameter
length and the two endpoints that realize it.

@Warning:
    This implementation assumes the graph is connected and undirected.

@Time: $O(n + m)$, where $n$ is the number of nodes and $m$ is the
number of edges

@Memory: $O(n)$
>8*/

#pragma once

#include "../../Contest/template.cpp"

pair<int, pair<int, int>> uug_diameter(const vector<vector<int>>& adj) {
    int n = adj.size();

    auto bfs = [&](int start) -> pair<int, int> {
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        int farthest = start;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : adj[v]) {
                if (dist[u] == -1) {
                    dist[u] = dist[v] + 1;
                    q.push(u);
                    if (dist[u] > dist[farthest]) {
                        farthest = u;
                    }
                }
            }
        }

        return {farthest, dist[farthest]};
    };

    int u = bfs(0).first;
    auto [v, diameter] = bfs(u);

    return {diameter, {u, v}};
}
