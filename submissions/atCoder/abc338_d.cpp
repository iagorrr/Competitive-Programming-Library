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
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define rep(i, begin, end)                              \
  for (__typeof(begin) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end));                  \
       i += 1 - 2 * ((begin) > (end)))

int lg2(ll x) {
  return __builtin_clzll(1) - __builtin_clzll(x);
}

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D",
// "LD", "L"}); int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}; int
// dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int T(1);

const ll oo = 1e18;
int N, M;

int get_clockwise_dist(int a, int b) {
  int clockwise_dist = 0;
  if (a < b) {
    clockwise_dist = b - a;
  } else {
    clockwise_dist = N - a;
    clockwise_dist += 1;      // from N to 1
    clockwise_dist += b - 1;  // from 1 to b
  }
  return clockwise_dist;
}

int get_counterclockwise_dist(int a, int b) {
  int counterclockwise_dist = 0;
  if (a > b) {
    counterclockwise_dist = a - b;
  } else {
    counterclockwise_dist = a - 1 + 1 + N - b;
  }
  return counterclockwise_dist;
}

ll findcost(vll &XS, int blocked) {
  ll ans = 0;
  for (int i = 0, a, b; i + 1 < M; i++) {
    a = XS[i], b = XS[i + 1];

    // clockwise
    int clockwise_dist = get_clockwise_dist(a, b);

    // counterclockwise
    int counterclockwise_dist =
      get_counterclockwise_dist(a, b);

    dbg(clockwise_dist, counterclockwise_dist, a, b);
    if (clockwise_dist <= counterclockwise_dist) {
      if (a < b) {
        int l = a - 1, r = b - 2;
        if (l <= blocked and blocked <= r)
          clockwise_dist = oo;
      } else {
        if (a != N) {
          int l = a - 1, r = N - 2;
          if (l <= blocked and blocked <= r)
            clockwise_dist = oo;
        }
        if (N - 1 == blocked) clockwise_dist = oo;
        if (a != 1) {
          if (0 <= blocked and blocked <= b - 2)
            clockwise_dist = oo;
        }
      }
    }

    if (counterclockwise_dist <= clockwise_dist) {
      if (a > b) {
        int l = b - 1, r = a - 2;
        if (l <= blocked and blocked <= r)
          counterclockwise_dist = oo;
      } else {
        if (a != 1) {
          if (0 <= blocked and blocked <= a - 2)
            counterclockwise_dist = oo;
        }
        if (blocked == N - 1) counterclockwise_dist = oo;
        if (b != N) {
          if (b - 1 <= blocked and blocked <= N - 2)
            counterclockwise_dist = oo;
        }
      }
    }

    ans += min(clockwise_dist, counterclockwise_dist);
  }

  return ans;
}

/*
 * - lenght = bridge crossing
 * - range increment the paths and remove the one which
 * passed the minimal number of times
 * - if there is two possible shortest paths increment both
 *  change the idea:
 *    - instead of mark 1 in each position of the path,
 * increment how much would cost if remove that edge, that
 * is the diference between the shortest and longest path
 *    - in the end remove the aresta tha increase the
 * minimal when removed
 *
 * lol you don't need a segTree for it:
 *  - mark the l and  r you updated and than make prefix sum
 * */
auto run() {
  cin >> N >> M;

  vi XS(M);
  for (auto &xi : XS) cin >> xi;
  vector<tuple<int, int, int>> to_increase;

  for (int i = 0; i + 1 < M; i++) {
    int a = XS[i];
    int b = XS[i + 1];

    int clockwise_dist = get_clockwise_dist(a, b);

    int counterclockwise_dist =
      get_counterclockwise_dist(a, b);

    ll diff = abs(clockwise_dist - counterclockwise_dist);
    dbg(clockwise_dist, counterclockwise_dist, a, b);
    if (clockwise_dist <= counterclockwise_dist) {
      if (a < b) {
        int l = a - 1, r = b - 2;
        to_increase.eb(l, r, diff);
      } else {
        if (a != N) {
          int l = a - 1, r = N - 2;
          to_increase.eb(l, r, diff);
        }

        to_increase.eb(N - 1, N - 1, diff);
        if (a != 1) to_increase.eb(0, b - 2, diff);
      }
    }

    if (counterclockwise_dist <= clockwise_dist) {
      if (a > b) {
        int l = b - 1, r = a - 2;

        to_increase.eb(l, r, diff);
      } else {
        if (a != 1) to_increase.eb(0, a - 2, diff);

        to_increase.eb(N - 1, N - 1, diff);
        if (b != N) to_increase.eb(b - 1, N - 2, diff);
      }
    }
  }

  vi extra_cost(N + 1);
  for (auto [l, r, d] : to_increase) {
    extra_cost[l] += d;
    extra_cost[r + 1] -= d;
  }

  for (int i = 1; i <= N; i++) {
    extra_cost[i] += extra_cost[i - 1];
  }

  int blocked =
    min_element(extra_cost.begin(), extra_cost.end() - 1) -
    extra_cost.begin();

  cout << findcost(XS, blocked) << '\n';
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> T;

  for (int t = 1; t <= T; t++) {
    run();
  }
}

// AC, graphs, greddy
