/*8<
  @Title:
    Tree Flatten (Euler Tour / DFS Order)

  @Description:
    Flattens a tree into a linear array using DFS traversal,
    assigning each node an entry time (tin) and exit time (tout).
    This allows tree queries to be converted into range queries
    on a flat array.

  @Usage:
    TreeFlatten tf(tree, root);
    auto [tin, tout] = tf.get\_range(u);  // get DFS range for node u
    bool is\_ancestor = tf.on\_subtree(u, v);  // check if v is in u's subtree

  @Time:
    Build $O(N)$, all queries $O(1)$
>8*/

struct TreeFlatten {
    vector<int> tin, tout;
    TreeFlatten(const vector<vector<int>> &tree, int root = 0)
        : tin(tree.size()), tout(tree.size()) {
        int timer = 0;
        dfs(root, -1, timer, tree);
    }

    void dfs(int u, int p, int &timer, const vector<vector<int>> &tree) {
        tin[u] = timer;
        timer++;

        for (int v : tree[u]) {
            if (v != p) {
                dfs(v, u, timer, tree);
            }
        }
        tout[u] = timer - 1;
    }

    pair<int, int> get_range(int u) { return {tin[u], tout[u]}; }

    bool on_subtree(int u, int v) {
        return tin[u] <= tin[v] and tout[v] <= tout[u];
    }
};
