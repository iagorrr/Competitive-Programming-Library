#include <bits/stdc++.h>

#include <queue>
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

void run() {
  int n;
  cin >> n;
  priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>>
    inuse;
  set<int> free;
  int lastid = 0;
  vi room(n);
  vector<array<ll, 3>> reach(n);
  for (int i = 0; i < n; i++) {
    cin >> reach[i][0] >> reach[i][1];
    reach[i][2] = i;
  }
  sort(all(reach));
  for (int j = 0; j < n; j++) {
    auto [a, b, i] = reach[j];

    while (not inuse.empty() and inuse.top()[0] < a) {
      free.insert(inuse.top()[2]);
      inuse.pop();
    }

    if (free.empty()) {
      lastid++;
      free.insert(lastid);
    }

    array<ll, 3> cur;
    cur[0] = b;
    cur[1] = a;
    cur[2] = *free.begin();
    room[i] = *free.begin();

    inuse.push(cur);
    free.erase(*free.begin());
  }

  cout << lastid << endl;
  for (int i = 0; i < n; i++) {
    cout << room[i] << " \n"[i == n - 1];
  }
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, sorting and searching, data structures
