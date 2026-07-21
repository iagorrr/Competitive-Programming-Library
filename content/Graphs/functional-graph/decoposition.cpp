/*8<
@Title: Functional Graph Decomposition (Cycle-Tree)

@Description: Decomposes a functional graph (a directed graph where every node
has out-degree exactly 1) into its constituent components using Kahn's
algorithm. It identifies all cycles, calculates their sizes, and determines the
shortest distance from every node to its respective cycle.

@Usage: Pass a 0-indexed vector $next$ where $next[u]$ is the outgoing edge
from node $u$. Returns a FunctionalGraph struct. Nodes in the same component
will eventually reach the same cycle, identified by $cycleIds[u]$.
Warning: Cases where a node has no outgoing edge (e.g., $next[u] = -1$) are
undefined behavior. Handle terminal nodes outside the decomposition or modify
the graph (e.g., making them point to themselves).

@Time: $O(N)$

@Memory: $O(N)$
>8*/

#include "../../Contest/template.cpp"
#include "./functional-graph.cpp"

FunctionalGraph f(const vector<int>& next) {
    const int n = next.size();
    vector<int> inDegree(n);

    for (int i = 0; i < n; i++) {
        inDegree[next[i]]++;
    }

    queue<int> q;
    for (int u = 0; u < n; u++) {
        if (inDegree[u] == 0) {
            q.push(u);
        }
    }

    vector<int> topologicOrder;
    topologicOrder.reserve(n);

    while (not q.empty()) {
        int curNode = q.front();
        q.pop();

        topologicOrder.push_back(curNode);

        int nextNode = next[curNode];
        inDegree[nextNode]--;

        if (inDegree[nextNode] == 0) q.push(nextNode);
    }

    vector<int> cycleSizes;
    vector<int> distanceToCycle(n);
    vector<int> cycleIds(n);

    for (int u = 0; u < n; u++) {
        if (inDegree[u] == 0) continue;

        int curNode = u;
        int cycleSize = 0;

        while (inDegree[curNode] != 0) {
            inDegree[curNode] = 0;

            distanceToCycle[curNode] = 0;
            cycleIds[curNode] = (int)cycleSizes.size();
            cycleSize++;

            curNode = next[curNode];
        }

        cycleSizes.push_back(cycleSize);
    }

    for (auto v : ranges::views::reverse(topologicOrder)) {
        int nv = next[v];
        cycleIds[v] = cycleIds[nv];
        distanceToCycle[v] = distanceToCycle[nv] + 1;
    }

    return {next, cycleIds, cycleSizes, distanceToCycle};
}
