/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define endl '\n'
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define int long long
#define all(j) j.begin(), j.end()
#define rall(j) j.rbegin(), j.rend()
#define len(j) (int)j.size()
#define rep(i, a, b) \
    for (common_type_t<decltype(a), decltype(b)> i = (a); i < (b); i++)
#define rrep(i, a, b) \
    for (common_type_t<decltype(a), decltype(b)> i = (a); i > (b); i--)
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) for (auto &xi : ranges::views::reverse(xs))
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define emp emplace
#define ins insert
#define divc(a, b) ((a) + (b) - 1ll) / (b)
using str = string;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vc = vector<char>;
using vs = vector<str>;
template <typename T, typename T2>
using umap = unordered_map<T, T2>;
template <typename T>
using pqmn = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using pqmx = priority_queue<T, vector<T>>;
template <typename T, typename U>
inline bool chmax(T &a, U const &b) {
    return (a < b ? a = b, 1 : 0);
}
template <typename T, typename U>
inline bool chmin(T &a, U const &b) {
    return (a > b ? a = b, 1 : 0);
}
/*8<============~ END TEMPLATE ~============}>8*/

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
        vector<pair<state, int>> aux;
        for (int i = 0; i < sz; i++) {
            aux.push_back({st[i], i});
        }

        sort(all(aux),
             [](const pair<state, int> &a, const pair<state, int> &b) {
                 return a.fi.len > b.fi.len;
             });

        for (auto &[stt, id] : aux) {
            if (stt.link != -1) {
                st[stt.link].cnt += st[id].cnt;
            }
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
};
void run();

int32_t main() {
#ifndef LOCAL
    fastio;
#endif

    int T = 1;

    /*cin >> T;*/

    rep(t, 0, T) {
        dbg(t);
        run();
    }
}

void run() {
    string S;
    cin >> S;
    SuffixAutomaton sa(S, len(S));
    cout << sa.totalSubstrings() << endl;
}

/*8<
>8*/
