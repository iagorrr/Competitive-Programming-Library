struct SegTree {
        int N;
        vector<ll> ns, lazy;

        SegTree(const vector<ll> &xs)
                : N(xs.size()), ns(4 * N, 0), lazy(4 * N, 0) {
                for (size_t i = 0; i < xs.size(); ++i) update(i, i, xs[i]);
        }

        void update(int a, int b, ll value) {
                update(1, 0, N - 1, a, b, value);
        }

        void update(int node, int L, int R, int a, int b, ll value) {
                // Lazy propagation
                if (lazy[node]) {
                        ns[node] ^= lazy[node];

                        if (L < R)  // Se o nó não é uma folha, propaga
                        {
                                lazy[2 * node] ^= lazy[node];
                                lazy[2 * node + 1] ^= lazy[node];
                        }

                        lazy[node] = 0;
                }

                if (a > R or b < L) return;

                if (a <= L and R <= b) {
                        ns[node] ^= value;

                        if (L < R) {
                                lazy[2 * node] ^= value;
                                lazy[2 * node + 1] ^= value;
                        }

                        return;
                }

                update(2 * node, L, (L + R) / 2, a, b, value);
                update(2 * node + 1, (L + R) / 2 + 1, R, a, b, value);

                ns[node] = ns[2 * node] ^ ns[2 * node + 1];
        }

        ll rxq(int a, int b) { return RSQ(1, 0, N - 1, a, b); }

        ll rxq(int node, int L, int R, int a, int b) {
                if (lazy[node]) {
                        ns[node] ^= lazy[node];

                        if (L < R) {
                                lazy[2 * node] ^= lazy[node];
                                lazy[2 * node + 1] ^= lazy[node];
                        }

                        lazy[node] = 0;
                }

                if (a > R or b < L) return 0;

                if (a <= L and R <= b) return ns[node];

                ll x = rxq(2 * node, L, (L + R) / 2, a, b);
                ll y = rxq(2 * node + 1, (L + R) / 2 + 1, R, a, b);

                return x ^ y;
        }
};
