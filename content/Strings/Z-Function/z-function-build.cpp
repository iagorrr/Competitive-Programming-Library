/*8<
@Title: Z-function building

@Description:
    The Z-function is an algorithm used to compute the Z-array of a given
string.For a string $s$, $Z[i]$ represents the length of the longest common
prefix between the string $s$ and the suffix of $s$ starting from the index $i$.

@Usage:
    The function z\_function\_build(s) takes a single argument s, which is a
string (or any container-like structure), and returns a vector of integers
representing the Z-function of the input.

    \begin{lstlisting}[language=c++]
    string s = "abacaba";
    vector<int> result = z_function_build(s);
    // result = [0, 0, 1, 0, 3, 0, 1]

    vector<int> v = {1, 2, 3, 1, 2, 3};
    vector<int> result_v = z_function_build(v);
    // result_v = [0, 1, 2, 3, 0, 1]
    \end{lstlisting}

@Warning:
        By definition $Z[0] = 0$, remember to treat it appart.
@Time: $O(n)$

@Memory: $O(n)$
>8*/

#pragma once
#include "../../Contest/template.cpp"

template <typename Seq>
vector<int> z_function_build(const Seq& s) {
    int n = int(s.size());
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}
