/*8<
@Title: Prefix Automaton (Z-Function Compressed)

@Description:
    Receives the output of the Z-function and builds a compressed
    automaton containing all prefixes of the original string.
    Each path on the automaton generates a distinct string.

    Think of it as a Z-function compressed automaton: positions
    that fall inside a Z-box are merged, so consecutive characters
    covered by the same Z-window become a single edge instead of
    one edge per character.

    Each edge is a tuple $\langle nxt, l, r \rangle$:
    \begin{compactitem}
        \item $nxt$: index of the next node
        \item $l, r$: the edge consumes substring $s[l \ldots r]$
        of the original string
    \end{compactitem}

    Every node also has a back-edge $\langle 1, 0, 0 \rangle$
    to node $1$, representing the first character $s[0]$.

@Time: $O(N)$
>8*/

using _edge = tuple<int, int, int>;
vector<vector<_edge>> preffixAutomaton(const vector<int> &z) {
    int n = z.size();

    vector<vector<_edge>> adj(2);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        r = max(r, z[i] + i);
        if (i < r) continue;

        int nxt = adj.size();
        adj.back().push_back({nxt, l + 1, r});
        adj.push_back({});
        l = i;
    }
    for (auto &x : adj) x.push_back({1, 0, 0});

    return adj;
}
