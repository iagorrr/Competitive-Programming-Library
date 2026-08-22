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

    sort(intervals.begin(), intervals.end());

    vector<Pt> ret{intervals.front()};
    for (int i = 1; i < len(intervals); i++) {
        auto &[pl, pr] = ret.back();
        auto &[l, r] = intervals[i];
        if (l <= pr)
            pr = max(pr, r);
        else
            ret.emplace_back(l, r);
    }

    return ret;
}
