/*8<
@Title: Z-function approximate pattern matching

@Description:
    This algorithm finds all positions in a string $s$ where the pattern $p$
    approximately occurs with up to $k$ consecutive mismatches.

    It works by leveraging the Z-function to check how many characters match
from the beginning (prefix) and end (suffix) of the pattern at each position in
$s$.

    The input sequences $s$ (text) and $p$ (pattern) can be strings or any
container supporting indexing and reversal.

@Time: $O(|s| + |p|)$

@Memory: $O(|s| + |p|)$

>8*/

#pragma once

#include "../../Contest/template.cpp"
#include "./z-function-build.cpp"

template <typename Seq>
vector<int> z_function_approximate_pattern_matching(Seq s, Seq p, int k) {
    if (s.empty() or p.empty()) return {};

    vector<int> z = z_function_build(p + "$" + s);

    reverse(begin(p), end(p));
    reverse(begin(s), end(s));

    vector<int> zr = z_function_build(p + "$" + s);

    vector<int> occurrences;

    int m = p.size();

    for (int i = m + 1; i + p.size() - 1 < z.size(); ++i) {
        int r = i + p.size() - 1 - 1 - p.size();
        int rr = (p.size() + 1) + (s.size() - 1 - r);
        if (z[i] + zr[rr] >= p.size() - k) occurrences.emplace_back(i - m - 1);
    }

    return occurrences;
}
