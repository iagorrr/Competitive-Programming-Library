#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...) 42
#endif
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
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)
int lg2(ll x) {
  return __builtin_clzll(1) - __builtin_clzll(x);
}

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D",
// "LD", "L"}); int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}; int
// dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll oo = 1e18;
int T(1);

int N, M;
string xs1[18278 + 100][999 + 100];
ll xs2[18278 + 100][999 + 100];

ll parser3(const string &s) {
  ll k = 1;
  ll ans = 0;
  for (auto it = s.rbegin(); it != s.rend(); it++) {
    ll i = *it - 'A' + 1;
    ans += i * k;
    k *= 26;
  }
  return ans-1;
}

pll parser2(string xs) {
  for (int i = 0; i < len(xs); i++) {
    if ('1' <= xs[i] and xs[i] <= '9') {
      ll b = parser3(xs.substr(0, i));
      ll a = stoll(xs.substr(i));
      a--;
      return {a, b};
    }
  }
  dbg(xs);
  assert(false);
}

vector<pll> parser(int x, int y) {
  vector<pll> ans;
  // string ori = xs1[x][y];
  // while (len(ori) > 1) {
  //   string cur;
  //   while (len(ori) > 1 and ori.back() != '+') {
  //     cur.push_back(ori.back());
  //     ori.pop_back();
  //   }
  //   ori.pop_back();
  //   reverse(all(cur));
  //   ans.push_back(parser2(cur));
  // }

  string cur;
  for (int i = 1; i < len(xs1[x][y]); i++) {
    if (xs1[x][y][i] == '+') {
      ans.push_back(parser2(cur));
      cur.clear();
    } else
      cur.push_back(xs1[x][y][i]);
  }
  ans.push_back(parser2(cur));
  return ans;
}

ll resolve(int i, int j) {
  if (xs2[i][j] != -1) return xs2[i][j];

  if (xs1[i][j].front() != '=')
    return xs2[i][j] = stoll(xs1[i][j]);

  auto deps = parser(i, j);

  ll ans = 0;
  for (auto [i2, j2] : deps) {
    ans += resolve(i2, j2);
  }

  return xs2[i][j] = ans;
}

auto solve() {
  cin >> M >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      xs2[i][j] = -1;
      cin >> xs1[i][j];
      if (xs1[i][j].front() != '=')
        xs2[i][j] = stoll(xs1[i][j]);
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << resolve(i, j) << " \n"[j == M - 1];
    }
  }
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  cin >> T;

  // dbg("AZ", parser3("AZ"));
  // dbg("AA", parser3("AA"));
  // cout << parser3("AZ") << endl;
  for (int i = 1; i <= T; i++) {
    solve();
  }
}

// AC, DAG, DP
