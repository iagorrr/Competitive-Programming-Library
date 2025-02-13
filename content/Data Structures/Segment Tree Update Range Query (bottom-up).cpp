/*
 * @Description:
 *      merge should be function<T(T,T)>, that
 *      makes the necessary operation between two
 *      nodes in the segment tree
 * */

#include "../../Contest/template.cpp"

template <typename T, T identity, auto merge>
struct SegTreeBottomUp {
    int size;
    vector<T> arr;

    SegTreeBottomUp(int n) {
        for (size = 1; size < n; size <<= 1);
        arr.resize(size << 1);
    }

    void assign(int pos, const T &val) {
        for (arr[pos += size] = val; pos >>= 1;)
            arr[pos] = merge(arr[pos << 1], arr[pos << 1 | 1]);
    }

    T query(int l, int r) {
        T ans_l = identity, ans_r = identity;
        for (l += size, r += size + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans_l = merge(ans_l, arr[l++]);
            if (r & 1) ans_r = merge(arr[--r], ans_r);
        }
        return merge(ans_l, ans_r);
    }

    SegTreeBottomUp(const vector<T> &vec) : SegTreeBottomUp(len(vec)) {
        copy(all(vec), begin(arr) + size);
        rrep(i, size - 1, 0) arr[i] = merge(arr[i << 1], arr[i << 1 | 1]);
    }
};

using SegTreeBottomUpSumQuery =
    SegTreeBottomUp<ll, 0ll, [](ll a, ll b) { return a + b; }>;
