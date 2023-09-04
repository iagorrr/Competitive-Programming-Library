using ld = long double;

const ld EPS = 1e-9;
bool equals(ld a, ld b) { return fabs(a - b) < EPS; }
struct point {
  ld x, y;
  int id;
  point(ld vx = 0.0, ld vy = 0.0, int vid = -666) : x(vx), y(vy), id(vid) {}

  bool operator<(point &other) const {
    if (not equals(x, other.x)) return x < other.x;
    return y < other.y;
  }

  bool operator==(point &other) {
    return equals(x, other.x) and equals(y, other.y);
  }
};

double dist(point &p1, point &p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }

double deg_to_rad(double d) { return d * M_PI / 180.0; }
double rad_to_deg(double r) { return r * 180.0 / M_PI; }

// rotate p by theta degrees CCW w.r.t. origin (0, 0)
point rotate(const point &p, double theta) {
  double rad = deg_to_rad(theta);
  return point(p.x * cos(rad) - p.y * sin(rad),
               p.x * sin(rad) + p.y * cos(rad));
}
