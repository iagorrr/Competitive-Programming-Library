/*
  @Title: Topological Sorting (Kahn)
  @Description:
    Finds the topological sorting in a DAG.
    If the given graph is not a DAG (contains a cycle),
    an empty vector is returned.
  @Time: O(V + E)
*/

#pragma once
#include "../Contest/template.cpp"

vector<int> toposort(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> in_degree(n, 0);

    for (int u = 0; u < n; ++u) {
        for (int v : graph[u]) {
            in_degree[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : graph[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (order.size() == n) {
        return order;
    } else {
        return {};
    }
}
