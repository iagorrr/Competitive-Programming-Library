#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int)__x.size()
using ll = long long;
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

template <typename T = ll>
struct SegTree {
  int n;
  T nu, nq;
  vector<T> st;
  SegTree(const vector<T> &v)
    : n(len(v)),
      nu(numeric_limits<T>::min()),
      nq(numeric_limits<T>::min()),
      st(n * 4 + 1, nu) {
    for (int i = 0; i < n; ++i) update(i, v[i]);
  }
  void update(int p, T v) { update(1, 0, n - 1, p, v); }
  T query(int l, int r) { return query(1, 0, n - 1, l, r); }

  void update(int node, int nl, int nr, int p, T v) {
    if (p < nl or p > nr) return;

    if (nl == nr) {
      st[node] = v;
      return;
    }

    update(left(node), nl, mid(nl, nr), p, v);
    update(right(node), mid(nl, nr) + 1, nr, p, v);

    st[node] = max(st[left(node)], st[right(node)]);
  }

  T query(int node, int nl, int nr, int ql, int qr) {
    if (ql <= nl and qr >= nr) return st[node];
    if (nl > qr or nr < ql) return nq;
    if (nl == nr) return st[node];

    return max(query(left(node), nl, mid(nl, nr), ql, qr),
               query(right(node), mid(nl, nr) + 1, nr, ql, qr));
  }

  int left(int p) { return p << 1; }
  int right(int p) { return (p << 1) + 1; }
  int mid(int l, int r) { return (r - l) / 2 + l; }
};
const int start = 0, endS = 1, cost = 2, profit = 3, quit = 4;
void dbg(vector<array<ll, 5>> jobs) {
  for (int i = 0; i < len(jobs); i++) {
    cout << i << " : ";
    for (auto &j : jobs[i]) cout << j << ' ';
    cout << endl;
  }
}
bool comp(const array<ll, 5> &a, const array<ll, 5> &b) {
  if (a[start] == b[start]) {
    if (a[quit] == b[quit]) {
      if (a[endS] == b[endS]) {
        if (a[cost] == b[cost]) {
          return a[profit] > b[profit];
        } else
          return a[cost] < b[cost];
      } else
        return a[endS] < b[endS];
    } else
      return a[quit] < a[quit];
  } else
    return a[start] < b[start];
}

int startbefore(const vector<array<ll, 5>> &xs, int i) {
  int ans = 0;
  int l = i+1, r = len(xs) - 1;
  while (l <= r) {
    int mid = (r - l) / 2 + l;
    if (xs[mid][start] < xs[i][quit]) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  return ans;
}

void run() {
  int n;
  ll s;
  cin >> n >> s;

  // start, end, cost, profit, quiting day
  vector<array<ll, 5>> jobs(n);
  for (int i = 0; i < n; i++) {
    cin >> jobs[i][0] >> jobs[i][1] >> jobs[i][2];
    jobs[i][profit] = (jobs[i][1] - jobs[i][0] + 1) * s - jobs[i][2];
    jobs[i][quit] = jobs[i][start] + (jobs[i][cost] + s - 1) / s;
  }
  sort(all(jobs), comp);
  // dbg(jobs);

  vll aux(n);
  for (int i = 0; i < n; i++) {
    aux[i] = jobs[i][profit];
  }
  SegTree<ll> seg(aux);

  int curjob = -1;
  ll curday = 1;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    // cout << "curjob : " << curjob << " ans: " << ans << endl;
    // cout << "i: " << i << endl;
    // cout << "i: " << i << " profit " << profit << endl;
    // cout << " lenjobs " << len(jobs) << " lenjobs[i]" << len(jobs[i]) <<endl;
    if (jobs[i][profit] <= 0) continue;
    if (curjob == -1) {
      ll startday = jobs[i][start];
      ll quitday = jobs[i][quit] - 1;
      int j = startbefore(jobs, i);

      // ll maxprofit = seg.query(startday, quitday);
      ll maxprofit = seg.query(i, j);

      if (maxprofit > jobs[i][profit]) continue;

      curjob = i;
    } else {
      ll startday = jobs[i][start];
      ll quitday = jobs[i][quit] - 1;

      int j = startbefore(jobs, i);
      ll maxprofit = seg.query(i, j);

      if (maxprofit > jobs[i][profit]) continue;

      ll curprofit = jobs[i][profit];
      ll profitleft = (jobs[curjob][endS] - startday + 1ll) * s;
      if (curprofit < profitleft) continue;
      if (curprofit == profitleft and jobs[i][quit] >= jobs[curjob][quit])
        continue;

      ll curincrease =
        (jobs[i][start] - jobs[curjob][start]) * s - jobs[curjob][cost];
      // cout << "curincrease : " << curincrease << endl;
      ans += max(0ll, curincrease);
      curjob = i;
    }
  }

  if (curjob != -1) {
    ll curincrease;
    curincrease = jobs[curjob][profit];
    ans += max(0ll, curincrease);
    // cout << "curincrease: " << curincrease << endl;
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
