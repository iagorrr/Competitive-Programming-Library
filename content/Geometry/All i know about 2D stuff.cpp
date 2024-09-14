#include <iterator>

#include "../Contest/template.cpp"

/*============================================================================*/

const double EPS{1e-4};
const ld PI = acos(-1);
enum PointPosition { IN, ON, OUT };
template <class Point>
vector<Point> segInter(Point a, Point b, Point c, Point d);
template <typename T>
bool equals(T a, T b) {
  if (std::is_floating_point<T>::value)
    return fabs(a - b) < EPS;
  else
    return a == b;
}

/*============================================================================*/

template <class T>
struct Point {
  typedef Point P;
  T x, y;
  explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
  bool operator<(P p) { return tie(x, y) < tie(p.x, p.y); }
  bool operator>(P& rhs) { return rhs < *this; }
  bool operator==(P p) { return tie(x, y) == tie(p.x, p.y); }
  P operator+(P p) { return P(x + p.x, y + p.y); }
  P operator-(P p) { return P(x - p.x, y - p.y); }
  P operator*(T d) { return P(x * d, y * d); }
  P operator/(T d) { return P(x / d, y / d); }
  T dot(P p) { return x * p.x + y * p.y; }
  T cross(P p) { return x * p.y - y * p.x; }
  T cross(P a, P b) { return (a - *this).cross(b - *this); }
  T dist2() { return x * x + y * y; }
  double dist() { return sqrt((double)dist2()); }
  // angle to x-axis in interval [-pi, pi]
  double angle() { return atan2(y, x); }
  P unit() { return *this / dist(); }  // makes dist()=1
  P perp() { return P(-y, x); }        // rotates +90 degrees
  P normal() { return perp().unit(); }
  // returns point rotated 'a' radians ccw around
  // the origin
  P rotate(double a) {
    return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
  }
  pair<T, T> slope(Point<T>& o) {
    auto a = o.x - x;
    auto b = o.y - y;
    if (!is_floating_point<T>::value) {
      auto g = __gcd(a, b);
      if (g) a /= g, b /= g;
    }
    return {b, a};
  }
  friend ostream& operator<<(ostream& os, P p) {
    return os << "(" << p.x << "," << p.y << ")";
  }

  double distanceTo(Point<T>& other) { return hypot(other.x - x, other.y - y); }
};

/*============================================================================*/

template <typename T>
struct Line {
  T a, b, c;
  Point<T> p1, p2;
  Line(T a = 0, T b = 0, T c = 0) : a(a), b(b), c(c) {
    if (a != 0) {
      double x = 0;
      double y = (-c) / b;
      p1 = Point<T>(x, y);
    }

    if (b != 0) {
      double y = 0;
      double x = (-c) / a;
      p2 = Point<T>(x, y);
    }
  }
  Line(Point<T>& p, Point<T>& q) {
    a = p.y - q.y;
    b = q.x - p.x;
    c = p.cross(q);
    p1 = p, p2 = q;
  }
  bool operator==(Line<T>& other) {
    return tie(a, b, c) == tie(other.a, other.b, other.c);
  }
  // Less-than operator
  bool operator<(Line& rhs) { return tie(a, b, c) < tie(rhs.a, rhs.b, rhs.c); }
  bool operator>(Line& rhs) { return rhs < *this; }
  Line<T> norm() {
    T d = a == 0 ? b : a;
    return Line(a / d, b / d, c / d);
  }
  bool contains(Point<T>& p) { return equals(a * p.x + b * p.y + c, (T)0); }
  bool parallel(Line<T>& r) {
    auto det = a * r.b - b * r.a;
    return equals(det, 0) and !(*this == r);
  }
  bool orthogonal(Line<T>& r) { return equals(a * r.a + b * r.b, 0); }
  T direction(Point<T>& p3) { return p1.cross(p2, p3); }
  friend ostream& operator<<(ostream& os, Line l) {
    return os << fixed << setprecision(6) << "(" << l.a << "," << l.b << ","
              << l.c << ")";
  }
  double distance(Point<T>& p) { return (a * p.x + b * p.y + c) / hypot(a, b); }

  Point<T> closest(Point<T>& p) {
    auto den = (a * a + b * b);
    auto x = (b * (b * p.x - a * p.y) - a * c) / den;
    auto y = (a * (-b * p.x + a * p.y) - b * c) / den;
    return Point<T>{x, y};
  }
};

/*============================================================================*/

template <typename T>
struct LineSegment {
  Point<T> p1, p2;
  LineSegment(Point<T> p, Point<T> q) { p1 = p, p2 = q; }

  LineSegment(T a, T b, T c, T d)
      : LineSegment(Point<T>(a, b), Point<T>(c, d)) {}
  bool operator==(LineSegment<T>& other) {
    return tie(p1, p2) == tie(other.p1, other.p2);
  }
  // Less-than operator
  bool operator<(LineSegment& rhs) { return tie(p1, p2) < tie(rhs.p1, rhs.p2); }
  bool operator>(LineSegment& rhs) { return rhs < *this; }
  T direction(Point<T>& p3) { return p1.cross(p2, p3); }
  friend ostream& operator<<(ostream& os, LineSegment l) {
    return os << "(" << l.p1 << "," << l.p2 << ")";
  }
  vector<Point<T>> intersection(LineSegment<T>& other) {
    return segInter(p1, p2, other.p1, other.p2);
  }

  // Verifica se o ponto P da reta r que contém A e B  pertence ao segmento
  bool contains(Point<T>& P) {
    return equals(p1.x, p2.x)
               ? min(p1.y, p2.y) <= P.y and P.y <= max(p1.y, p2.y)
               : min(p1.x, p2.x) <= P.x and P.x <= max(p1.x, p2.x);
  }

  // Ponto mais próximo de P no segmento AB
  Point<T> closest(Point<T>& P) {
    Line<T> r(p1, p2);
    auto Q = r.closest(P);

    if (this->contains(Q)) return Q;

    auto distp1 = P.distanceTo(p1);
    auto distp2 = P.distanceTo(p2);

    if (distp1 <= distp2)
      return p1;
    else
      return p2;
  }
};

/*============================================================================*/

template <typename T>
struct Circle {
  Point<T> c;
  T r;
  Circle(Point<T> _c, T _r) : c(_c), r(_r) {}
  Circle(T _r) : Circle(Point<T>(0, 0), _r) {}
  ld area() const { return PI * r * r; }
  ld perimeter() const { return 2.0 * PI * r; }
  ld arc(ld theta) const { return theta * r; }
  ld chord(ld theta) const { return 2.0 * r * sin(theta / 2.0); }
  ld sector(ld theta) const { return (theta * r * r) / 2.0; }
  ld segment(ld theta) const { return ((theta - sin(theta)) * r * r) / 2.0; }
  PointPosition position(const Point<T>& p) const {
    auto d = c.dist(p);
    return equals(d, r) ? ON : (d < r ? IN : OUT);
  }
};

/*============================================================================*/

template <typename T>
struct Rectangle {
  Point<T> P, Q;
  T b, h;
  Rectangle(const Point<T>& p, const Point<T>& q) : P(P), Q(q) {
    assert(P != Q);
    b = max(P.x, Q.x) - min(P.x, Q.x);
    h = max(P.y, Q.y) - min(P.y, Q.y);
  }
  Rectangle(T base, T height) : P(0, 0), Q(base, height), b(base), h(height) {}
  T perimeter() const { return 2 * b + 2 * h; }
  T area() const { return b * h; }
  optional<Rectangle> intersection(const Rectangle& r) const {
    using pt = pair<T, T>;
    auto i = pt(min(P.x, Q.x), max(P.x, Q.x));
    auto u = pt(min(r.P.x, r.Q.x), max(r.P.x, r.Q.x));
    auto a = max(i.first, u.first);
    auto b = min(i.second, u.second);

    i = pt(min(P.y, Q.y), max(P.y, Q.y));
    u = pt(min(r.P.y, r.Q.y), max(r.P.y, r.Q.y));
    auto c = max(i.first, u.first);
    auto d = max(i.second, u.first);

    if (d < c or b < a) return nullopt;

    return {{a, c}, {b, d}};
  }
};

/*============================================================================*/

template <typename T>
struct Trapezium {
  T B, b, h;
  T area() const { return ((b + B) * h) / 2; }
};

/*============================================================================*/

template <typename T>
struct Triangle {
  Point<T> A, B, C;
  enum SidesClass { EQUILATERAL, ISOCELES, SCALENE };
  SidesClass classification_by_sides() const {
    auto a = A.distanceTo(B);
    auto b = B.distanceTo(C);
    auto c = C.distanceTo(A);
    if (equals(a, b) && equals(b, c)) return EQUILATERAL;
    if (equals(a, b) or equals(a, c) or equals(b, c)) return ISOCELES;
    return SCALENE;
  }

  enum AnglesClass { RIGHT, ACUTE, OBTUSE };

  AnglesClass classification_by_angles() const {
    auto a = dist(A, B);
    auto b = dist(B, C);
    auto c = dist(C, A);

    auto alpha = acos((a * a - b * b - c * c) / (-2 * b * c));
    auto beta = acos((b * b - a * a - c * c) / (-2 * a * c));
    auto gamma = acos((c * c - a * a - b * b) / (-2 * a * b));

    auto right = PI / 2.0;

    if (equals(alpha, right) || equals(beta, right) || equals(gamma, right))
      return RIGHT;

    if (alpha > right || beta > right || gamma > right) return OBTUSE;

    return ACUTE;
  }

  double perimeter() const {
    auto a = dist(A, B), b = dist(B, C), c = dist(C, A);

    return a + b + c;
  }
  double area() const {
    Line<T> r(A, B);

    auto b = dist(A, B);
    auto h = r.distance(C);

    return (b * h) / 2;
  }
};

template <typename T>
Point<T> triangleBarycenter(const Point<T>& a, const Point<T>& b,
                            const Point<T>& c) {
  return Point<T>((a.x + b.x + c.x) / 3.0, (a.y + b.y + c.y) / 3.0);
}

template <typename T>
Point<T> triangleOrthocenter(const Point<T>& a, const Point<T>& b,
                             const Point<T>& c) {
  Line<T> r(a, b), s(a, c);
  Line<T> u{r.b, -r.a, -(c.x * r.b - c.y * r.a)};
  Line<T> v{s.b, -s.a, -(b.x * s.b - b.y * s.a)};
  auto det = u.a * v.b - u.b * v.a;
  auto x = (-u.c * v.b + v.c * u.b) / det;
  auto y = (-v.c * u.a + u.c * v.a) / det;
  return {x, y};
}

template <typename T>
Point<double> triangleIncenter(const Point<T>& a, const Point<T>& b,
                               const Point<T>& c) {
  auto dab = distance(a, b);
  auto dbc = distance(b, c);
  auto dca = distance(c, a);
  auto p = dab + dbc + dca;
  auto x = (a.x * dab + b.x * dbc + b.x * dca) / (p);
  auto y = (a.y * dab + b.y * dbc + b.y * dca) / (p);
  return Point<double>(x, y);
}

template <typename T>
Point<T> triangleCircumcenter(const Point<T>& A, const Point<T>& B,
                              const Point<T>& C) {
  auto D = 2 * (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));

  auto A2 = A.x * A.x + A.y * A.y;
  auto B2 = B.x * B.x + B.y * B.y;
  auto C2 = C.x * C.x + C.y * C.y;

  auto x = (A2 * (B.y - C.y) + B2 * (C.y - A.y) + C2 * (A.y - B.y)) / D;
  auto y = (A2 * (C.x - B.x) + B2 * (A.x - C.x) + C2 * (B.x - A.x)) / D;

  return {x, y};
}
template <typename T>
Point<T> triangleCircumradius(const Point<T>& a, const Point<T>& b,
                              const Point<T>& c) {
  auto dab = distance(a, b);
  auto dbc = distance(b, c);
  auto dca = distance(c, a);
  return (dab + dbc + dca) / triangleArea(a, b, c);
}

/*============================================================================*/

template <class Point>
vector<Point> segInter(Point a, Point b, Point c, Point d) {
  auto oa = c.cross(d, a), ob = c.cross(d, b), oc = a.cross(b, c),
       od = a.cross(b, d);
  // Checks if intersection is single non-endpoint
  // point.
  if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
    return {(a * ob - b * oa) / (ob - oa)};
  set<Point> s;
  if (onSegment(c, d, a)) s.insert(a);
  if (onSegment(c, d, b)) s.insert(b);
  if (onSegment(a, b, c)) s.insert(c);
  if (onSegment(a, b, d)) s.insert(d);
  return {all(s)};
}

/*============================================================================*/

template <typename T>
double angle(const Point<T>& P, const Point<T>& Q, const Point<T>& R,
             const Point<T>& S) {
  auto ux = P.x - Q.x;
  auto uy = P.y - Q.y;

  auto vx = R.x - S.x;
  auto vy = R.y - S.y;

  auto num = ux * vx + uy * vy;
  auto den = hypot(ux, uy) * hypot(vx, vy);

  // Caso especial: se den == 0, algum dos vetores é degenerado: os dois
  // pontos são iguais. Neste caso, o ângulo não está definido

  return acos(num / den);
}

/*============================================================================*/

struct pt {
  double x, y;
  int id;
};

int orientation(pt a, pt b, pt c) {
  double v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
  if (v < 0) return -1;  // clockwise
  if (v > 0) return +1;  // counter-clockwise
  return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
  int o = orientation(a, b, c);
  return o < 0 || (include_collinear && o == 0);
}
bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

void convex_hull(vector<pt>& pts, bool include_collinear = false) {
  pt p0 = *min_element(all(pts), [](pt a, pt b) {
    return make_pair(a.y, a.x) < make_pair(b.y, b.x);
  });
  sort(all(pts), [&p0](const pt& a, const pt& b) {
    int o = orientation(p0, a, b);
    if (o == 0)
      return (p0.x - a.x) * (p0.x - a.x) + (p0.y - a.y) * (p0.y - a.y) <
             (p0.x - b.x) * (p0.x - b.x) + (p0.y - b.y) * (p0.y - b.y);
    return o < 0;
  });
  if (include_collinear) {
    int i = len(pts) - 1;
    while (i >= 0 && collinear(p0, pts[i], pts.back())) i--;
    reverse(pts.begin() + i + 1, pts.end());
  }

  vector<pt> st;
  for (int i = 0; i < len(pts); i++) {
    while (st.size() > 1 &&
           !cw(st[len(st) - 2], st.back(), pts[i], include_collinear))
      st.pop_back();
    st.push_back(pts[i]);
  }

  pts = st;
}

/*============================================================================*/

/*8<
  @Time: $O(N)$
>8*/
template <typename T>
double ccRadius(const Point<T>& A, const Point<T>& B, const Point<T>& C) {
  return (B - A).dist() * (C - B).dist() * (A - C).dist() /
         abs((B - A).cross(C - A)) / 2;
}

template <typename T>
Point<T> ccCenter(const Point<T>& A, const Point<T>& B, const Point<T>& C) {
  Point<T> b = C - A, c = B - A;
  return A + (b * c.dist2() - c * b.dist2()).perp() / b.cross(c) / 2;
}

template <typename T>
pair<Point<T>, double> mec(vector<Point<T>> ps) {
  shuffle(all(ps), mt19937(time(0)));
  Point<T> o = ps[0];
  double r = 0, EPS = 1 + 1e-8;
  rep(i, 0, len(ps)) if ((o - ps[i]).dist() > r * EPS) {
    o = ps[i], r = 0;
    rep(j, 0, i) if ((o - ps[j]).dist() > r * EPS) {
      o = (ps[i] + ps[j]) / 2;
      r = (o - ps[i]).dist();
      rep(k, 0, j) if ((o - ps[k]).dist() > r * EPS) {
        o = ccCenter(ps[i], ps[j], ps[k]);
        r = (o - ps[i]).dist();
      }
    }
  }
  return {o, r};
}

/*============================================================================*/

template <typename T>
Line<T> perpendicular_bisector(const Point<T>& P, const Point<T>& Q) {
  auto a = 2 * (Q.x - P.x);
  auto b = 2 * (Q.y - P.y);
  auto c = (P.x * P.x + P.y * P.y) - (Q.x * Q.x + Q.y * Q.y);

  return {a, b, c};
}

/*============================================================================*/

ll cross(ll x1, ll y1, ll x2, ll y2) { return x1 * y2 - x2 * y1; }

ll polygonArea(vector<pll>& pts) {
  ll ats = 0;
  for (int i = 2; i < len(pts); i++)
    ats += cross(pts[i].first - pts[0].first, pts[i].second - pts[0].second,
                 pts[i - 1].first - pts[0].first,
                 pts[i - 1].second - pts[0].second);
  return abs(ats / 2ll);
}

ll boundary(vector<pll>& pts) {
  ll ats = pts.size();
  for (int i = 0; i < len(pts); i++) {
    ll deltax = (pts[i].first - pts[(i + 1) % pts.size()].first);
    ll deltay = (pts[i].second - pts[(i + 1) % pts.size()].second);
    ats += abs(__gcd(deltax, deltay)) - 1;
  }
  return ats;
}

pll latticePoints(vector<pll>& pts) {
  ll bounds = boundary(pts);
  ll area = polygonArea(pts);
  ll inside = area + 1ll - bounds / 2ll;

  return {inside, bounds};
}

/*============================================================================*/

template <typename T>
bool contains(const Point<T>& A, const Point<T>& B, const Point<T>& P) {
  // Verifica se P está na região retangular
  auto xmin = min(A.x, B.x);
  auto xmax = max(A.x, B.x);
  auto ymin = min(A.y, B.y);
  auto ymax = max(A.y, B.y);

  if (P.x < xmin || P.x > xmax || P.y < ymin || P.y > ymax) return false;

  // Verifica relação de semelhança no triângulo
  return equals((P.y - A.y) * (B.x - A.x), (P.x - A.x) * (B.y - A.y));
}

/*============================================================================*/
// the polygon area of a intersection between a circle and a ccw polygon
template <typename T>
#define arg(p, q) atan2(p.cross(q), p.dot(q))
double circlePoly(Point<T> c, double r, vector<Point<T>> ps) {
  auto tri = [&](Point<T> p, Point<T> q) {
    auto r2 = r * r / 2;
    Point<T> d = q - p;
    auto a = d.dot(p) / d.dist2(), b = (p.dist2() - r * r) / d.dist2();
    auto det = a * a - b;
    if (det <= 0) return arg(p, q) * r2;
    auto s = max(0., -a - sqrt(det)), t = min(1., -a + sqrt(det));
    if (t < 0 || 1 <= s) return arg(p, q) * r2;
    Point<T> u = p + d * s, v = p + d * t;
    return arg(p, u) * r2 + u.cross(v) / 2 + arg(v, q) * r2;
  };
  auto sum = 0.0;
  rep(i, 0, len(ps)) sum += tri(ps[i] - c, ps[(i + 1) % len(ps)] - c);
  return sum;
}

/*============================================================================*/

bool checkIfPolygonIsConvex(vector < Point<T>) {
  if (n < 3) return false;
}
