struct SegmentTree {
        int N;
        vll ns, lazy;
        SegmentTree(const vll &xs)
                : N(xs.size()), ns(4 * N, INT_MAX), lazy(4 * N, 0) {
                for (size_t i = 0; i < xs.size(); ++i) update(i, i, xs[i]);
        }
        void update(int a, int b, ll value) {
                update(1, 0, N - 1, a, b, value);
        }
        void update(int node, int L, int R, int a, int b, ll value) {
                if (lazy[node]) {
                        ns[node] = ns[node] == INT_MAX ? lazy[node]
                                                       : ns[node] + lazy[node];
                        if (L < R) {
                                lazy[2 * node] += lazy[node];
                                lazy[2 * node + 1] += lazy[node];
                        }
                        lazy[node] = 0;
                }
                if (a > R or b < L) return;
                if (a <= L and R <= b) {
                        ns[node] =
                                ns[node] == INT_MAX ? value : ns[node] + value;
                        if (L < R) {
                                lazy[2 * node] += value;
                                lazy[2 * node + 1] += value;
                        }
                        return;
                }
                update(2 * node, L, (L + R) / 2, a, b, value);
                update(2 * node + 1, (L + R) / 2 + 1, R, a, b, value);
                ns[node] = min(ns[2 * node], ns[2 * node + 1]);
        }
        ll RMQ(int a, int b) { return RMQ(1, 0, N - 1, a, b); }
        ll RMQ(int node, int L, int R, int a, int b) {
                if (lazy[node]) {
                        ns[node] = ns[node] == INT_MAX ? lazy[node]
                                                       : ns[node] + lazy[node];
                        if (L < R) {
                                lazy[2 * node] += lazy[node];
                                lazy[2 * node + 1] += lazy[node];
                        }
                        lazy[node] = 0;
                }
                if (a > R or b < L) return INT_MAX;

                if (a <= L and R <= b) return ns[node];
                ll x = RMQ(2 * node, L, (L + R) / 2, a, b);
                ll y = RMQ(2 * node + 1, (L + R) / 2 + 1, R, a, b);
                return min(x, y);
        }
};
