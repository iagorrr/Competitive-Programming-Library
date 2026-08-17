#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"
#include "../Contest/template.cpp"
#include "./suffix-automaton.cpp"

signed main() {
    fastio;
    string s;
    cin >> s;
    SuffixAutomaton sa(s, len(s));
    // number of distinct substrings = sum over states of len[v]-len[link[v]]
    cout << sa.totalSubstrings() << endl;
}
