/*============================================================================*/

#pragma once
#include "../Contest/template.cpp"

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
