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
};
