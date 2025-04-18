/*8<
@Title: Pattern Matching

@Description:
    The Pattern Matching algorithm uses the Z-function to efficiently find all
occurrences of a pattern $p$ in a text $S$. The Z-function is first computed for
the concatenation of the pattern and text ($p + \$ + S$), where \$ is a unique
separator character that does not appear in either $p$ or $S$. The Z-array
allows us to quickly determine where in the text the pattern occurs by comparing
segments of the text with the pattern.

@Usage:
    The function $pattern\_matching(s, p)$ takes two arguments: $s$, the text,
and $p$, the pattern to search for. It returns a vector of integers, each of
which represents the starting index of a match of the pattern $p$ in the text
$S$.

    \begin{lstlisting}[language=c++]
    string text = "abacabadabacaba";
    string pattern = "abac";
    vector<int> result = pattern_matching(text, pattern);
    // result = [0, 8]

    string text_v = "ababab";
    string pattern_v = "ab";
    vector<int> result_v = pattern_matching(text_v, pattern_v);
    // result_v = [0, 2, 4]
    \end{lstlisting}

@Warning:
    The pattern must be non-empty, and the text must also be non-empty. Ensure
that the separator character \$ is not present in the pattern or text.

@Time: $O(n + m)$, where $n$ is the length of the text $S$ and $m$ is the length
of the pattern $p$.

@Memory: $O(n + m)$
>8*/

#pragma once

#include "../../Contest/template.cpp"
#include "./z-function-build.cpp"

template <typename Seq>
vector<int> z_function_pattern_matching(const Seq& s, const Seq& p) {
    if (s.empty() or p.empty()) return {};

    Seq concatenated = p + "$" + s;

    vector<int> z = z_function_build(concatenated);

    vector<int> occurrences;

    int m = p.size();

    for (int i = m + 1; i < z.size(); ++i) {
        if (z[i] == m) occurrences.push_back(i - m - 1);
    }

    return occurrences;
}
