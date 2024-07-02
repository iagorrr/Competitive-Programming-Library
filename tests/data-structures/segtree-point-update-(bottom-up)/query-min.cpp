#include <bits/stdc++.h>
using namespace std;

#include "../../../algorithms/data-structures/segtree-point-update-(bottom-up)/query-min.cpp"

void test_update() {
        const int n = 8;
        SegTree st(n);

        for (int i = 0; i < n; i++) {
                st.assign(i, i);
        }

        for (int i = 0; i < n; i++) {
                assert(st.query(i,i).value == i);
        }
}

void test_query() {
        const vector<int> xs = {-1, 1'000, 34, -200, 4, 1, -100000, 0};

        SegTree st((int)xs.size());
        for (int i = 0; i < (int)xs.size(); i++) {
                st.assign(i, xs[i]);
        }

        assert(st.query(0, 0).value == -1);
        assert(st.query(0, 1).value == -1);
        assert(st.query(0, 2).value == -1);
        assert(st.query(0, 3).value == -200);
        assert(st.query(0, 4).value == -200);
        assert(st.query(0, 5).value == -200);
        assert(st.query(0, 6).value == -100000);
        assert(st.query(0, 7).value == -100000);

        assert(st.query(1, 1).value == 1'000);
        assert(st.query(1, 2).value == 34);
        assert(st.query(1, 3).value == -200);
        assert(st.query(1, 4).value == -200);
        assert(st.query(1, 5).value == -200);
        assert(st.query(1, 6).value == -100000);
        assert(st.query(1, 7).value == -100000);

        assert(st.query(2, 2).value == 34);
        assert(st.query(2, 3).value == -200);
        assert(st.query(2, 4).value == -200);
        assert(st.query(2, 5).value == -200);
        assert(st.query(2, 6).value == -100000);
        assert(st.query(2, 7).value == -100000);

        assert(st.query(3, 3).value == -200);
        assert(st.query(3, 4).value == -200);
        assert(st.query(3, 5).value == -200);
        assert(st.query(3, 6).value == -100000);
        assert(st.query(3, 7).value == -100000);

        assert(st.query(4, 4).value == 4);
        assert(st.query(4, 5).value == 1);
        assert(st.query(4, 6).value == -100000);
        assert(st.query(4, 7).value == -100000);

        assert(st.query(5, 5).value == 1);
        assert(st.query(5, 6).value == -100000);
        assert(st.query(5, 7).value == -100000);

        assert(st.query(6, 6).value == -100000);
        assert(st.query(6, 7).value == -100000);

        assert(st.query(7, 7).value == 0);
}


int32_t main() {
        test_update();
        test_query();
}


