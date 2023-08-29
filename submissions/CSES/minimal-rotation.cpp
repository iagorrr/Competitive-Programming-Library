#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int)__x.size()
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)
 
const ll INF = 1e18;
 
struct state {
  int len, link, cnt, firstpos;
  // this can be optimized using a vector with the alphabet size
  map<char, int> next;
};
struct SuffixAutomaton {
  vector<state> st;
  int sz = 0;
  int last;
 
  SuffixAutomaton(const string &s, int maxlen)
    : st(maxlen * 2) {
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
    for (auto &c : s) add_char(c);
  }
 
  void add_char(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    st[cur].firstpos = st[cur].len - 1;
    int p = last;
    // follow the suffix link until find a transition to c
    while (p != -1 and !st[p].next.count(c)) {
      st[p].next[c] = cur;
      p = st[p].link;
    }
    // there was no transition to c so create and leave
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
};
void run() {
  string s;
  cin >> s;
  string ans;
  string aux = s + s;
  SuffixAutomaton sa(aux, len(aux) + 4);
  int cur = 0;
  while (len(ans) < len(s)) {
    if (cur == -1 or sa.st[cur].next.empty()) break;
		auto &[c, nxt] = *sa.st[cur].next.begin();
		ans += c;
		cur = nxt;
  }
  cout << ans << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// TLE in one test
