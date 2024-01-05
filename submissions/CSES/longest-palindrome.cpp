#include <bits/stdc++.h>

#include <algorithm>
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
vi manacher(const string &s) {
  int n = len(s) - 2;  // bc of $ and ^
  vi p(n + 2);
  int l = 1, r = 1;
  for (int i = 1; i <= n; i++) {
    p[i] = max(0, min(r - i, p[l + (r - i)]));
    while (s[i - p[i]] == s[i + p[i]]) p[i]++;
    if (i + p[i] > r) l = i - p[i], r = i + p[i];
    p[i]--;
  }
  return p;
}

string longest_palindrome(const string &s) {
  string t("$#");
  for (auto c : s) t.push_back(c), t.push_back('#');
  t.push_back('^');

  vi xs = manacher(t);

  int mpos = max_element(all(xs)) - xs.begin();

  string p;
  for (int k = xs[mpos], i = mpos - k; i <= mpos + k; i++)
    if (t[i] != '#') p.push_back(t[i]);

  return p;
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
