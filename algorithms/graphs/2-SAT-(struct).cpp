struct SAT2 {
        ll n;
        vll2d adj, adj_t;
        vc used;
        vll order, comp;
        vc assignment;
        bool solvable;
        SAT2(ll _n)
                : n(2 * _n),
                  adj(n),
                  adj_t(n),
                  used(n),
                  order(n),
                  comp(n, -1),
                  assignment(n / 2) {}
        void dfs1(int v) {
                used[v] = true;
                for (int u : adj[v]) {
                        if (!used[u]) dfs1(u);
                }
                order.push_back(v);
        }

        void dfs2(int v, int cl) {
                comp[v] = cl;
                for (int u : adj_t[v]) {
                        if (comp[u] == -1) dfs2(u, cl);
                }
        }

        bool solve_2SAT() {
                // find and label each SCC
                for (int i = 0; i < n; ++i) {
                        if (!used[i]) dfs1(i);
                }
                reverse(all(order));
                ll j = 0;
                for (auto &v : order) {
                        if (comp[v] == -1) dfs2(v, j++);
                }

                assignment.assign(n / 2, false);
                for (int i = 0; i < n; i += 2) {
                        // x and !x belong to the same SCC
                        if (comp[i] == comp[i + 1]) {
                                solvable = false;
                                return false;
                        }

                        assignment[i / 2] = comp[i] > comp[i + 1];
                }
                solvable = true;
                return true;
        }

        void add_disjunction(int a, bool na, int b, bool nb) {
                // na and nb signify whether a and b are to be negated
                /* in the graph the vertices with indices  2k  and  2k+1  are
                 the two vertices corresponding to variable  k  with  2k+1 
                 corresponding to the negated variable.
                */
                a = (2 * a) ^ na;
                b = (2 * b) ^ nb;
                int neg_a = a ^ 1;
                int neg_b = b ^ 1;
                adj[neg_a].push_back(b);
                adj[neg_b].push_back(a);
                adj_t[b].push_back(neg_a);
                adj_t[a].push_back(neg_b);
        }
};
