/*8<
@Title: Functional Graph (Cycle-Tree Decomposition + Optional Binary Lifting)

@Description: Decomposes a functional graph into cycle-tree components in $O(N)$
time and space, calculating cycle sizes, node positions, and distances.
Optionally builds a binary lifting table to support $k$-th successor
and distance queries.

@Usage: Instantiate passing a 0-indexed vector $next$ where $next[u]$
is the outgoing edge.
IMPORTANT: Must call `buildBinaryLifting()` before using `kth()` or `dist()`.
- $kth(u, k)$: handles arbitrarily large $k$ efficiently using modulo on cycles.
- $dist(u, v)$: returns shortest distance or -1 if unreachable.
Warning: Cases where a node has no outgoing edge (e.g., $next[u] = -1$) are
undefined behavior. Handle terminal nodes outside the decomposition.

@Time: Construction $O(N)$, buildBinaryLifting $O(N \log N)$, kth $O(\log N)$,
dist $O(\log N)$

@Memory: $O(N)$ base, $O(N \log N)$ with binary lifting
>8*/

#include "../../Contest/template.cpp"

struct FunctionalGraph {
    int n;
    vector<int> next;
    vector<int> cycleIds;
    vector<int> cycleSizes;
    vector<int> distanceToCycle;
    vector<int> cyclePos;
    vector<vector<int>> succ;

    FunctionalGraph(const vector<int>& next) : n(next.size()), next(next) {
        cycleIds.assign(n, 0);
        distanceToCycle.assign(n, 0);
        cyclePos.assign(n, -1);

        vector<int> inDegree(n, 0);
        for (int i = 0; i < n; i++) {
            inDegree[next[i]]++;
        }

        queue<int> q;
        for (int u = 0; u < n; u++) {
            if (inDegree[u] == 0) q.push(u);
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

        for (int u = 0; u < n; u++) {
            if (inDegree[u] == 0) continue;

            int curNode = u;
            int cycleSize = 0;

            while (inDegree[curNode] != 0) {
                inDegree[curNode] = 0;

                distanceToCycle[curNode] = 0;
                cycleIds[curNode] = (int)cycleSizes.size();
                cyclePos[curNode] = cycleSize;
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
    }

    void buildBinaryLifting() {
        if (!succ.empty()) return;

        int maxLog = __lg(n) + 1;
        succ.assign(maxLog, vector<int>(n));
        succ[0] = next;

        for (int k = 1; k < maxLog; k++) {
            for (int i = 0; i < n; i++) {
                succ[k][i] = succ[k - 1][succ[k - 1][i]];
            }
        }
    }

    int kth(int u, ll k) const {
        if (k <= 0) return u;

        // Fast-forward huge K by reaching the cycle and applying modulo
        if (k > distanceToCycle[u]) {
            ll distToC = distanceToCycle[u];
            k -= distToC;

            int maxLog = succ.size();
            for (int i = 0; i < maxLog; i++) {
                if ((1ll << i) & distToC) u = succ[i][u];
            }

            k %= cycleSizes[cycleIds[u]];
        }

        // Advance the remaining K <= N steps
        int maxLog = succ.size();
        for (int i = 0; i < maxLog; i++) {
            if ((1ll << i) & k) u = succ[i][u];
        }

        return u;
    }

    int dist(int u, int v) const {
        if (cycleIds[u] != cycleIds[v]) return -1;

        // Check if v is an ancestor of u in the tree paths
        if (distanceToCycle[u] >= distanceToCycle[v]) {
            int diff = distanceToCycle[u] - distanceToCycle[v];
            if (kth(u, diff) == v) return diff;
        }

        // If v is in the cycle, u can definitely reach it
        if (distanceToCycle[v] == 0) {
            int u_entry = kth(u, distanceToCycle[u]);
            int cSize = cycleSizes[cycleIds[u]];

            // O(1) distance inside the cycle using positions
            int distInCycle = (cyclePos[v] - cyclePos[u_entry] + cSize) % cSize;
            return distanceToCycle[u] + distInCycle;
        }

        return -1;
    }
};
