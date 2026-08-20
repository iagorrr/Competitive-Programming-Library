#define PROBLEM "https://judge.yosupo.jp/problem/longest_common_substring"
#include "../Contest/template.cpp"
#include "./suffix-automaton.cpp"

signed main() {
    fastio;
    string s, t;
    cin >> s >> t;
    SuffixAutomaton sa(s, len(s));
    // {startIdx, len} of the longest common substring inside t
    auto [tStart, l] = sa.LCS(t);
    if (l == 0) {
        cout << "0 0 0 0" << endl;
        return 0;
    }
    // recover where that same substring first occurs in s
    int sStart = sa.firstOccurence(t.substr(tStart, l));
    // output a b c d with s[a..b) == t[c..d)
    cout << sStart << ' ' << sStart + l << ' ' << tStart << ' ' << tStart + l
         << endl;
}
