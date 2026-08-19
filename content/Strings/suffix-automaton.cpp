#pragma once
#include "../Contest/template.cpp"

struct SuffixAutomaton {
    struct state {
        int len, link, cnt, firstpos;
        // this can be optimized using a vector with
        // the alphabet size
        map<char, int> next;
        vi inv_link;
    };
    vector<state> st;
    int sz = 0;
    int last;
    vc cloned;

    SuffixAutomaton(const string &s, int maxlen)
        : st(maxlen * 2), cloned(maxlen * 2) {
        st[0].len = 0;
        st[0].link = -1;
        sz++;
        last = 0;
        for (auto &c : s) add_char(c);

        // precompute for count occurences
        for (int i = 1; i < sz; i++) {
            st[i].cnt = !cloned[i];
        }
        vi cntLen(maxlen + 2, 0), order(sz);
        for (int i = 0; i < sz; i++) cntLen[st[i].len]++;
        for (int i = 1; i <= maxlen; i++) cntLen[i] += cntLen[i - 1];
        for (int i = 0; i < sz; i++) order[--cntLen[st[i].len]] = i;

        for (int i = sz - 1; i >= 1; i--) {
            int v = order[i];
            st[st[v].link].cnt += st[v].cnt;
        }

        // for find every occurende position
        for (int v = 1; v < sz; v++) {
            st[st[v].link].inv_link.push_back(v);
        }
    }

    void add_char(char c) {
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        st[cur].firstpos = st[cur].len - 1;
        int p = last;
        // follow the suffix link until find a
        // transition to c
        while (p != -1 and !st[p].next.count(c)) {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        // there was no transition to c so create and
        // leave
        if (p == -1) {
            st[cur].link = 0;
            last = cur;
            return;
        }

        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            cloned[clone] = true;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            st[clone].firstpos = st[q].firstpos;
            while (p != -1 and st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
        last = cur;
    }

    bool checkOccurrence(const string &t) {  // O(len(t))
        int cur = 0;
        for (auto &c : t) {
            if (!st[cur].next.count(c)) return false;
            cur = st[cur].next[c];
        }
        return true;
    }
    ll totalSubstrings() {  // distinct, O(len(s))
        ll tot = 0;
        for (int i = 1; i < sz; i++) {
            tot += st[i].len - st[st[i].link].len;
        }
        return tot;
    }

    // count occurences of a given string t
    int countOccurences(const string &t) {
        int cur = 0;
        for (auto &c : t) {
            if (!st[cur].next.count(c)) return 0;
            cur = st[cur].next[c];
        }
        return st[cur].cnt;
    }

    // find the first index where t appears a
    // substring O(len(t))
    int firstOccurence(const string &t) {
        int cur = 0;
        for (auto c : t) {
            if (!st[cur].next.count(c)) return -1;
            cur = st[cur].next[c];
        }
        return st[cur].firstpos - len(t) + 1;
    }

    vi everyOccurence(const string &t) {
        int cur = 0;
        for (auto c : t) {
            if (!st[cur].next.count(c)) return {};
            cur = st[cur].next[c];
        }
        vi ans;
        getEveryOccurence(cur, len(t), ans);
        return ans;
    }

    void getEveryOccurence(int v, int P_length, vi &ans) {
        if (!cloned[v]) ans.pb(st[v].firstpos - P_length + 1);
        for (int u : st[v].inv_link) getEveryOccurence(u, P_length, ans);
    }

    // O(len(t))
    // Longest Common Substring between both
    pair<int, int> LCS(const string &t) {
        int v = 0, l = 0, best = 0, bestpos = -2;

        for (int i = 0; i < t.size(); i++) {
            auto it = st[v].next.find(t[i]);
            while (v && it == st[v].next.end()) {
                v = st[v].link;
                l = st[v].len;
                it = st[v].next.find(t[i]);
            }
            if (it != st[v].next.end()) {
                v = it->second;
                l++;
            }
            if (l > best) {
                best = l;
                bestpos = i;
            }
        }

        // {startIdx, len} in T
        return {bestpos - best + 1, best};
    }
};
