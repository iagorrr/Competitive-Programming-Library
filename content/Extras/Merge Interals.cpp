/*8<
        @Time: $(N \log N)$
        @Space: $O(N)$
        @Warning: It destroys the original array
>8*/
#include "../Contest/template.cpp"

template <typename T>
vector<pair<T, T>> merge_intervals(vector<pair<T, T>> &intervals) {
    if (!len(intervals)) return {};

    using Pt = pair<T, T>;

    sort(all(intervals));

    vector<Pt> ret{intervals.front()};
    rep(i, 1, len(ret)) {
        auto &[pl, pr] = ret.back();
        auto &[l, r] = intervals[i];
        if (l <= pr)
            chmax(pr, r);
        else
            ret.eb(l, r);
    }

    return ret;
}
