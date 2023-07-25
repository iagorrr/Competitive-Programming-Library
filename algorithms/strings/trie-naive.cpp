//  time: O(n^2) memory: O(n^2)
using Node = map<char, int>;
using vi = vector<int>;
using Trie = vector<Node>;

Trie build(const string &s) {
        int n = (int)s.size();
        Trie trie(1);
        string suffix;

        for (int i = n - 1; i >= 0; --i) {
                suffix = s.substr(i) + '#';

                int v = 0;  // root
                for (auto c : suffix) {
                        if (c == '#') {  // makrs the poistion of an occurence
                                trie[v][c] = i;
                                break;
                        }
                        if (trie[v][c])
                                v = trie[v][c];
                        else {
                                trie.push_back({});
                                trie[v][c] = trie.size() - 1;
                                v = trie.size() - 1;
                        }
                }
        }
        return trie;
}

vi search(Trie &trie, string s) {
        int p = 0;
        vi occ;
        for (auto &c : s) {
                p = trie[p][c];
                if (!p) return occ;
        }

        queue<int> q;
        q.push(0);
        while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                for (auto [c, v] : trie[cur]) {
                        if (c == '#')
                                occ.push_back(v);
                        else
                                q.push(v);
                }
        }
        return occ;
}

ll distinct_substr(const Trie &trie) {
        ll cnt = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
                auto u = q.front();
                q.pop();

                for (auto [c, v] : trie[u]) {
                        if (c != '#') {
                                cnt++;
                                q.push(v);
                        }
                }
        }
        return cnt;
}
