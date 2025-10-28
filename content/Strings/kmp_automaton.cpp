// arthur stuff
// updates kmp vector when appending a new char
// to erase the last char, just pi.pop_back()
// pi = kmp result vector
// aut = kmp automaton
vector<int> pi;
vector<vector<int>> aut(n + 1, vector<int>(26));
auto update = [&](string &st, char ch) -> void {
    st.push_back(ch);
    int i = st.size() - 1;
    for (int c = 0; c < 26; c++) {
        if (i && (c + 'a') != st[i])
            aut[i][c] = aut[pi[i - 1]][c];
        else
            aut[i][c] = i + ('a' + c == st[i]);
    }
    if (i)
        pi.push_back(aut[pi[i - 1]][ch - 'a']);
    else
        pi.push_back(0);
};
