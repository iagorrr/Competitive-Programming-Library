/*8<
@Title: Process all partitions of a set

@Description: generate every distinct group of a set that contains elements from
0 to N-1, and pass it to the given function "process". If N is 4 the sets
generated would be :

        [\{\{0,1,2,3\}\}]
        [\{\{0,1,2\},\{3\}\}]
        [\{\{0,1,3\},\{2\}\}]
        [\{\{0,1\},\{2,3\}\}]
        [\{\{0,1\},\{2\},\{3\}\}]
        [\{\{0,2,3\},\{1\}\}]
        [\{\{0,2\},\{1,3\}\}]
        [\{\{0,2\},\{1\},\{3\}\}]
        [\{\{0,3\},\{1,2\}\}]
        [\{\{0\},\{1,2,3\}\}]
        [\{\{0\},\{1,2\},\{3\}\}]
        [\{\{0,3\},\{1\},\{2\}\}]
        [\{\{0\},\{1,3\},\{2\}\}]
        [\{\{0\},\{1\},\{2,3\}\}]
        [\{\{0\},\{1\},\{2\},\{3\}\}]

@Time: $O(B(N))$, Bell Number of N
@Memory: $O(N)$

>8*/
#include "../Contest/template.cpp"

void process_all_partitions_of_a_set(
    const int N, const function<void(const vi2d &)> process) {
    vi2d groups;
    groups.reserve(N);

    function<void(int)> _dfs = [&](int idx) {
        if (idx == N) {
            process(groups);
            return;
        }

        rep(i, 0, len(groups)) {
            groups[i].eb(idx);
            _dfs(idx + 1);
            groups[i].ppb();
        }

        groups.pb({idx});
        _dfs(idx + 1);
        groups.ppb();
    };
    _dfs(0);
}
