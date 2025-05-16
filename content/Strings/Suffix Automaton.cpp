/*8<
@Title: Suffix Automaton
@Description: A suffix automaton $A$ for a string $s$ is a minimal finite
automaton that recognizes the suffixes of $s$.
>8*/

#pragma once

#include "../Contest/template.cpp"

struct SuffixAutomaton {
    int n;
    vi suffix_link, max_len;
    vi2d transition;

    SuffixAutomaton(const string &s, int alphabet_size='z'-'a'+1, int norm = 'a') : n(len(s), suffix_link(n<<1), max_len(n<<1) , transition(n<<1, vi(alphabet_size, -1){
        int last = 0;
        trav(c, s) {
            int max_len_cur = max_len[last] + 1;
            while
        }
    }
};
