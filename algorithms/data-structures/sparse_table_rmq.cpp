/*
        Sparse table implementation for rmq.
        build: O(NlogN)
        query: O(1)
*/
int fastlog2(ll x) {
        ull i = x;
        return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}
template <typename T>
class SparseTable {
       public:
        int N;
        int K;
        vector<vector<T>> st;
        SparseTable(vector<T> vs)
                : N((int)vs.size()),
                  K(fastlog2(N) + 1),
                  st(K + 1, vector<T>(N + 1)) {
                copy(vs.begin(), vs.end(), st[0].begin());

                for (int i = 1; i <= K; ++i)
                        for (int j = 0; j + (1 << i) <= N; ++j)
                                st[i][j] = min(st[i - 1][j],
                                               st[i - 1][j + (1 << (i - 1))]);
        }
        T RMQ(int l, int r) {  // [l, r], 0 indexed
                int i = fastlog2(r - l + 1);
                return min(st[i][l], st[i][r - (1 << i) + 1]);
        }
};
