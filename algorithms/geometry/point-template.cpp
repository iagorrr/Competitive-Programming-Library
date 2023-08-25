
const ld EPS = 1e-6;

typedef ld T;
bool eq(T a, T b) { return abs(a - b) <= EPS; }
struct point {
  T x, y;
  int id;
  point(T x = 0, T y = 0) : x(x), y(y) {}
  point operator+(const point &o) const { return {x + o.x, y + o.y}; }
  point operator-(const point &o) const { return {x - o.x, y - o.y}; }
  point operator*(T t) const { return {x * t, y * t}; }
  point operator/(T t) const { return {x / t, y / t}; }
  T operator*(const point &o) const {
    return x * o.x + y * o.y;
  }  // dot product
  T operator^(const point &o) const {
    return x * o.y - y * o.x;
  }  // cross product
};

ld dist(point a, point b) {
  point d = a - b;
  return sqrt(d * d);
}
