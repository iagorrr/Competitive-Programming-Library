/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define endl '\n'
#define fastio                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
#define int long long
#define all(j) j.begin(), j.end()
#define rall(j) j.rbegin(), j.rend()
#define len(j) (int)j.size()
#define rep(i, a, b)                           \
  for (common_type_t<decltype(a), decltype(b)> \
           i = (a);                            \
       i < (b); i++)
#define rrep(i, a, b)                          \
  for (common_type_t<decltype(a), decltype(b)> \
           i = (a);                            \
       i > (b); i--)
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) \
  for (auto &xi : ranges::views::reverse(xs))
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
#define divc(a, b) ((a) + (b)-1ll) / (b)
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
using pqmn =
    priority_queue<T, vector<T>, greater<T>>;
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

vector<int> sort_cyclic_shifts(string const &s) {
  int n = s.size();
  const int alphabet = 128;

  vector<int> p(n), c(n),
      cnt(max(alphabet, n), 0);
  for (int i = 0; i < n; i++) cnt[s[i]]++;
  for (int i = 1; i < alphabet; i++)
    cnt[i] += cnt[i - 1];
  for (int i = 0; i < n; i++) p[--cnt[s[i]]] = i;
  c[p[0]] = 0;
  int classes = 1;
  for (int i = 1; i < n; i++) {
    if (s[p[i]] != s[p[i - 1]]) classes++;
    c[p[i]] = classes - 1;
  }

  vector<int> pn(n), cn(n);
  for (int h = 0; (1 << h) < n; ++h) {
    for (int i = 0; i < n; i++) {
      pn[i] = p[i] - (1 << h);
      if (pn[i] < 0) pn[i] += n;
    }
    fill(cnt.begin(), cnt.begin() + classes, 0);
    for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;
    for (int i = 1; i < classes; i++)
      cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; i--)
      p[--cnt[c[pn[i]]]] = pn[i];
    cn[p[0]] = 0;
    classes = 1;
    for (int i = 1; i < n; i++) {
      pair<int, int> cur = {
          c[p[i]], c[(p[i] + (1 << h)) % n]};
      pair<int, int> prev = {
          c[p[i - 1]],
          c[(p[i - 1] + (1 << h)) % n]};
      if (cur != prev) ++classes;
      cn[p[i]] = classes - 1;
    }
    c.swap(cn);
  }

  return p;
}

vector<int> suffix_array(string s) {
  s += "$";
  vector<int> p = sort_cyclic_shifts(s);
  p.erase(p.begin());
  return p;
}

vector<int> longestCommonPrefix(
    const string &s, const vector<int> &suf) {
  int n = s.size();
  vector<int> isuf(n), res(n - 1);
  for (int i = 0; i < n; ++i) isuf[suf[i]] = i;
  int k = 0;
  for (; isuf[k] != n - 1; ++k) {
    int cmp_i = suf[isuf[k] + 1];
    int r = k == 0 ? 0
                   : max(res[isuf[k - 1]] - 1,
                         (int)0);
    while (k + r < n && cmp_i + r < n &&
           s[k + r] == s[cmp_i + r])
      ++r;
    res[isuf[k]] = r;
  }
  ++k;
  for (int i = k; i < n; ++i) {
    int cmp_i = suf[isuf[i] + 1];
    int r = i == k ? 0
                   : max(res[isuf[i - 1]] - 1,
                         (int)0);
    while (i + r < n && cmp_i + r < n &&
           s[i + r] == s[cmp_i + r])
      ++r;
    res[isuf[i]] = r;
  }
  return res;
}

ll distinct_substrings(const string &s,
                       const vi &sa) {
  int n = len(s);
  vi lcp = longestCommonPrefix(s, sa);
  ll ans = n - sa[0];
  rep(i, 1, n) { ans += n - sa[i] - lcp[i - 1]; }
  return ans;
}
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
  auto sa = suffix_array(S);
  cout << distinct_substrings(S, sa) << endl;
}

/*8<
>8*/
