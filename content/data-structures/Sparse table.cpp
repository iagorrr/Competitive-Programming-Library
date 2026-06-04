template <typename T = long long,
          auto cmp = [](T &src1, T &src2, T &dst) { dst = min(src1, src2); }>
class SparseTable {
   private:
    int sz;
    vector<int> logs;
    vector<vector<T>> st;

   public:
    SparseTable(const vector<T> &v) : sz((int)v.size()), logs(sz + 1) {
        for (int i = 2; i < (sz + 1); i++) logs[i] = logs[i >> 1] + 1;
        st.resize(logs[sz] + 1, vector<T>(sz));
        for (int i = 0; i < sz; i++) st[0][i] = v[i];
        for (int k = 1; (1 << k) <= sz; k++) {
            for (int i = 0; i + (1 << k) <= sz; i++) {
                cmp(st[k - 1][i], st[k - 1][i + (1 << (k - 1))], st[k][i]);
            }
        }
    }
    T query(int l, int r) {
        r++;
        const int k = logs[r - l];
        T ret;
        cmp(st[k][l], st[k][r - (1 << k)], ret);
        return ret;
    }
};
