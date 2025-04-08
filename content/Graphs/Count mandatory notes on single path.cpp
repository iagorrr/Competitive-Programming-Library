/*8<
 * @Title: Count mandatory nodes on a single path
 *
 * @Description: Given a $startNode$ and an $endNode$, count the mandatory nodes
 * in the path from $startNode$ to $endNode$, that is the number of nodes such
 * that are present in every possible such path.
 *
 * @Warning: The $startNode$ and $endNode$ is always included in the counting,
 * ajust your final answer depending on the problem.
 *
 * @Time: $O(N+M)$
 *
 * @Memory: $O(N)$
 *
 * @Problems:
 * https://codeforces.com/group/btcK4I5D5f/contest/601720/problem/I
 * >8*/

#pragma once
#include "../Contest/template.cpp"
#include "./Block-Cut tree.cpp"

int BlockCutTree::countMandatoryNodesOnPath(int startNode, int endNode) {
    startNode = idOnTree[startNode], endNode = idOnTree[endNode];

    int ans = !isTreeCutpoint[startNode] + !isTreeCutpoint[endNode];

    int artPoints = 0;
    function<void(int, int)> dfsCount = [&](int u, int p) {
        artPoints += isTreeCutpoint[u];

        if (u == endNode) ans += artPoints;

        for (auto v : treeAdj[u]) {
            if (v != p) {
                dfsCount(v, u);
            }
        }

        artPoints -= isTreeCutpoint[u];
    };

    dfsCount(startNode, -1);

    return ans;
}
