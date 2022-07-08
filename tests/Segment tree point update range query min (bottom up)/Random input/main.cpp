#include "../../../content/Contest/template.cpp"
#include "../../../content/Data Structures/Segment Tree Point Update Range Query (bottom-up)/Query min.cpp"

int32_t main() {
    fastio;

    int N;
    cin >> N;

    vll AS(N);
    trav(ai, AS) cin >> ai;

    SegTreeBottomUpMinQuery seg(AS);

    int Q;
    cin >> Q;

    rep(q, 0, Q) {
        int l, r;
        cin >> l >> r;

        cout << seg.query(l, r) << endl;
    }
}
