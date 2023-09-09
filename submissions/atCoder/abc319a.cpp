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

void run() {
  stringstream input(
    "tourist 3858 ksun48 3679 Benq 3658 Um_nik 3648 apiad 3638 Stonefeang 3630 "
    "ecnerwala 3613 mnbvmar 3555 newbiedmy 3516 semiexp 3481");
  string str;
  int pt;
  int cnt = 0;
  map<string, int> mp;
  while (input >> str >> pt) {
    mp[str] = pt;
  }
  cin >> str;
  cout << mp[str] << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, ad-hoc
