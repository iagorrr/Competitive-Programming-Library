#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int)__x.size()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
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

const ll oo = 1e18;
vi manacher(string s) {
  string t2;
  for (auto c : s) t2 += string("#") + c;
  t2 = t2 + '#';
  int n = t2.size();
  t2 = "$" + t2 + "^";
  vi p(n + 2);
  int l = 1, r = 1;
  for (int i = 1; i <= n; i++) {
    p[i] = max(0, min(r - i, p[l + (r - i)]));
    while (t2[i - p[i]] == t2[i + p[i]]) {
      p[i]++;
    }
    if (i + p[i] > r) {
      l = i - p[i], r = i + p[i];
    }
    p[i]--;
  }
  return vi(begin(p) + 1, end(p) - 1);
}
string longest_palindrome(const string &s) {
  vi xs = manacher(s);

  string s2;
  for (auto c : s) s2 += string("#") + c;
  s2 = s2 + '#';

  int mpos = 0;
  for (int i = 0; i < len(xs); i++) {
    if (xs[i] > xs[mpos]) {
      mpos = i;
    }
  }

  string ans;
  int k = xs[mpos];
  for (int i = mpos - k; i <= mpos + k; i++) {
    if (s2[i] != '#') {
      ans += s2[i];
    }
  }
  return ans;
}
void run() {
  string s;
  cin >> s;
  auto ans = longest_palindrome(s);
  cout << ans << endl;
}

int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, strings, longest palindrome,  mancher
