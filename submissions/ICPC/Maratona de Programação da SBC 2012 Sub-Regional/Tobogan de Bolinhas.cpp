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

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D", "LD", "L"});
// int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
// int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll oo = 1e18;
using a3 = array<int, 3>;

const int MAXN(1'000 + 1);
int N;
int L, H;
vector<a3> XS(MAXN);

template <typename T>
bool equals(T a, T b) {
  const double EPS{1e-9};
  if (is_floating_point<T>::value)
    return fabs(a - b) < EPS;
  else
    return a == b;
}

template <typename T>
struct Point {
  T x, y;

  Point(T xv = 0, T yv = 0) : x(xv), y(yv) {}

  double distance(const Point<T> &P) const {
    return hypot(static_cast<double>(P.x - this->x),
                 static_cast<double>(P.y - this->y));
  }
};

template <typename T>
struct Line {
  T a, b, c;

  Line(T av, T bv, T cv) : a(av), b(bv), c(cv) {}

  Line(const Point<T> &P, const Point<T> &Q)
    : a(P.y - Q.y), b(Q.x - P.x), c(P.x * Q.y - Q.x * P.y) {}

  // verify if a point belongs to the line
  bool contains(const Point<T> &P) { return equals(a * P.x + b * P.y + c, 0); }

  // shortest distance between P and a point Q that belongs to this line
  double distance(const Point<T> &P) const {
    return fabs(a * P.x + b * P.y + c) / hypot(a, b);
  }

  // the closest point in this line to the given point
  Point<T> closest(const Point<T> &P) const {
    auto den = (a * a) + (b * b);

    auto x = (b * (b * P.x - a * P.y) - a * c) / den;
    auto y = (a * (-b * P.x + a * P.y) - b * c) / den;

    return Point<T>{x, y};
  }
};

template <typename T>
double distance(const Point<T> &P, const Point<T> &Q) {
  return hypot(static_cast<double>(P.x - Q.x), static_cast<double>(P.y - Q.y));
}

template <typename T>
struct Segment {
  Point<T> A, B;

  Segment(const Point<T> &a, const Point<T> &b) : A(a), B(b) {}

  /*
   * Verify if a given point P belongs to the segment,
   * considering that P belongs to the line defined with A and B
   */
  bool contains(const Point<T> &P) const {
    return equals(A.x, B.x) ? min(A.y, B.y) <= P.y and P.y <= max(A.y, B.y)
                            : min(A.x, B.x) <= P.x and P.x <= max(A.x, B.x);
  }

  /*
   * Verify if P belongs to the segment AB,
   * even if P don't belong to the line defined with A and B
   * */
  bool contains2(const Point<T> &P) const {
    double dAB = dist(A, B), dAP = dist(A, P), dPB = dist(P, B);
    return equals(dAP + dPB, dAB);
  }

  /*
   * Find the closest point in P that belongs to the segment
   * */
  Point<T> closest(const Point<T> &P) {
    Line<T> r(A, B);
    auto Q = r.closest(P);

    if (this->contains(Q)) return Q;

    auto distA = P.distance(A);
    auto distB = P.distance(B);

    return distA <= distB ? A : B;
  }

  double distToClosest(const Point<T> &P) { return closest(P).distance(P); }
};

auto solve() {
  cin >> L >> H;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < 3; j++) cin >> XS[i][j];
  }

  double ans = 1'001.999999999;

  for (int i = 1; i <= N; i++) {
    auto &[yi, xf, yf] = XS[i];

    if (i & 1)
      ans = min(ans, (double)L - (double)xf);
    else
      ans = min(ans, (double)xf);
  }

  for (int i = 1; i < N; i++) {
    auto &[yia, xfa, yfa] = XS[i];
    auto &[yib, xfb, yfb] = XS[i + 1];

    Point<double> af((double)xfa, (double)yfa), bi(i & 1 ? L : 0, (double)yib),
      bf((double)xfb, (double)yfb);

    Segment<double> segB(bi, bf);
    auto d = segB.distToClosest(af);
    ans = min({ans, d});
  }

  cout << fixed << setprecision(2) << ans << endl;
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  while (cin >> N) solve();
}

// AC, geometry, line, point, segment
