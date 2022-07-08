/*8<
@Title: Find smallest period using Z-function

@Description:
    Finds the smallest period $p$ of a sequence $s$, such that $s$ is a
repetition of its prefix of length $p$, i.e. $s = t + t + \dots + t$ with $t =
s[0..p)$. If no such $p < n$ exists, returns $n$ (the full length).

    Uses the Z-function to efficiently check where the prefix fully matches the
remaining suffix.

@Usage:
    The function z\_function\_find\_period(s) takes a sequence s (string,
vector, etc.) and returns an integer representing the smallest period.

    \begin{lstlisting}[language=c++]
    string s = "ababab";
    int period = z_function_find_period(s);
    // period = 2

    vector<int> v = {1, 2, 3, 1, 2, 3};
    int period_v = z_function_find_period(v);
    // period_v = 3
    \end{lstlisting}

@Time: $O(n)$
@Memory: $O(n)$
>8*/

#pragma once
#include "../../Contest/template.cpp"
#include "./z-function-build.cpp"

template <typename Seq>
int z_function_find_period(Seq &s) {
    auto z = z_function_build(s);
    int n = s.size();
    for (int i = 1; i < n; i++) {
        if ((n % i) == 0 and i + z[i] == n) {
            return i;
        }
    }
    return n;
}
