// TODO: improve this shit documentation i made
#include "../Contest/template.cpp"

/*
 * Receives a undirected graph where each edge
 * also have a unique identifier.
 * It also accepts multi edge, that is more than a one edge between a pair of
 * nodes.
 * It already assumes that the graph have an Eulerian cycle, so just use it if
 * you are sure of this
 * It also works for not fully connected graphs.
 * It returns the direction that each edge will be used in the Eulerian
 * cycle(s), already in the order to traverse such cycle(s).
 * It does a iterative dfs over the graph.
 * */
vector<tuple<int, int, int>> getEulerianCycleEdges(
    const vector<vector<pair<int, int>>>& adj) {
    const int n = adj.size();

    vector<char> isEdgeProcessed(n, 0);
    vector<tuple<int, int, int>> edgesDirection;
    vector<int> adjIdx(n, 0);

    for (int startNode = 0; startNode < n; startNode++) {
        if (adjIdx[startNode] == adj[startNode].size()) continue;

        vector<int> stack;
        stack.push_back(startNode);

        while (not stack.empty()) {
            int curNode = stack.back();

            if (adjIdx[curNode] < adj[curNode].size()) {
                auto [nxtNode, edgeIdx] = adj[curNode][adjIdx[curNode]];
                adjIdx[curNode]++;

                if (not isEdgeProcessed[edgeIdx]) {
                    isEdgeProcessed[edgeIdx] = 1;
                    edgesDirection.emplace_back(edgeIdx, curNode, nxtNode);

                    stack.push_back(nxtNode);
                }
            } else {
                stack.pop_back();
            }
        }
    }

    return edgesDirection;
}
