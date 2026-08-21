/*8<
  @Title:
    DSU on Tree (Sack)

  @Description:
    Answers offline subtree queries in $O(N\log N)$ using the
    small-to-large trick. For every vertex it processes the light
    children first (adding then discarding their subtrees), keeps
    the heavy child's contribution, re-adds the light subtrees and
    the vertex itself, then takes a snapshot for that vertex. Each
    element is added $O(\log N)$ times.

    The traversal is driven by four callbacks:
    \textbf{ADD(u)} inserts vertex $u$ into the current structure,
    \textbf{ANS(u)} records the answer for $u$ (whole subtree of
    $u$ is present), \textbf{DEL(u)} removes $u$, and the optional
    \textbf{EMPTY()} is called after a light subtree is fully erased
    (handy to reset aggregates in $O(1)$ instead of per-element
    deletions).

    \textbf{runPairs / goPairs} is a variant for aggregating over
    \emph{pairs} of vertices whose LCA is the current root $u$. It
    adds a fifth callback \textbf{QRY(a, u)}: before a light subtree
    is merged, every one of its vertices $a$ is queried against the
    structure, which at that moment holds the heavy child plus all
    earlier-processed light subtrees. Because the heavy child is
    processed first and light subtrees one by one, each unordered
    pair sharing LCA $u$ is reported exactly once (with $a$ taken
    from the later subtree in processing order). Same $O(N\log N)$
    bound.

  @Usage:
    Sack sack(g, root);
    unordered\_map<int,int> cnt; int distinct = 0;
    auto add = [\&](int u){ distinct += !cnt[c[u]]++; };
    auto ans = [\&](int u){ res[u] = distinct; };
    auto del = [\&](int u){ distinct -= !--cnt[c[u]]; };
    sack.run(add, ans, del); // 3-arg form: no EMPTY callback

  @Time:
    $O(N\log N)$ times the cost of one callback.

>8*/

#pragma once
#include "../Contest/template.cpp"

struct Sack {
    int n, root, timer;
    vector<vector<int>> g;
    vector<int> par, sz, heavy, tin, tout, ord;

    Sack(const vector<vector<int>>& g_, int root_)
        : n(g_.size()),
          root(root_),
          g(g_),
          par(n, -1),
          sz(n, 0),
          heavy(n, -1),
          tin(n),
          tout(n),
          ord(n) {
        timer = 0;
        dfs(root);
    }

    void dfs(int u) {
        sz[u] = 1;
        tin[u] = timer;
        ord[timer++] = u;
        for (int v : g[u])
            if (v != par[u]) {
                par[v] = u;
                dfs(v);
                sz[u] += sz[v];
                if (heavy[u] == -1 || sz[v] > sz[heavy[u]]) heavy[u] = v;
            }
        tout[u] = timer;
    }

    template <class FA, class FS, class FD, class FE>
    void go(int u, bool keep, FA& ADD, FS& SNAP, FD& DEL, FE& EMPTY) {
        for (int v : g[u])
            if (v != par[u] && v != heavy[u])
                go(v, false, ADD, SNAP, DEL, EMPTY);
        if (heavy[u] != -1) go(heavy[u], true, ADD, SNAP, DEL, EMPTY);
        for (int v : g[u])
            if (v != par[u] && v != heavy[u])
                for (int i = tin[v]; i < tout[v]; i++) ADD(ord[i]);
        ADD(u);
        SNAP(u);
        if (!keep) {
            for (int i = tin[u]; i < tout[u]; i++) DEL(ord[i]);
            EMPTY();
        }
    }

    template <class FA, class FS, class FD, class FE>
    void run(FA ADD, FS ANS, FD DEL, FE EMPTY) {
        go(root, true, ADD, ANS, DEL, EMPTY);
    }

    template <class FA, class FS, class FD>
    void run(FA ADD, FS ANS, FD DEL) {
        auto E = [] {};
        go(root, true, ADD, ANS, DEL, E);
    }

    template <class FA, class FS, class FD, class FE, class FQ>
    void goPairs(int u, bool keep, FA& ADD, FS& SNAP, FD& DEL, FE& EMPTY,
                 FQ& QRY) {
        // process light children first, discarding their structures
        for (int v : g[u])
            if (v != par[u] && v != heavy[u])
                goPairs(v, false, ADD, SNAP, DEL, EMPTY, QRY);

        // keep the heavy child's structure as the base to merge into
        if (heavy[u] != -1) goPairs(heavy[u], true, ADD, SNAP, DEL, EMPTY, QRY);

        for (int v : g[u])
            if (v != par[u] && v != heavy[u]) {
                // match this light subtree against everything merged so far
                for (int i = tin[v]; i < tout[v]; i++) QRY(ord[i], u);
                // then merge it in for the next sibling / for u itself
                for (int i = tin[v]; i < tout[v]; i++) ADD(ord[i]);
            }

        QRY(u, u);  // pairs with one endpoint equal to u
        ADD(u);
        SNAP(u);  // whole subtree of u is now present

        if (!keep) {
            for (int i = tin[u]; i < tout[u]; i++) DEL(ord[i]);
            EMPTY();
        }
    }

    template <class FA, class FQ, class FS, class FD, class FE>
    void runPairs(FA ADD, FS SNAP, FD DEL, FE EP, FQ QRY) {
        goPairs(root, true, ADD, SNAP, DEL, EP, QRY);
    }
};
