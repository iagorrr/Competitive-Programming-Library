struct point {
  int x, y;
  int id;

  point operator-(const point &o) const {
    return {x - o.x, y - o.y};
  }
  int operator^(const point &o) const {
    return x * o.y - y * o.x;
  }
};

/*
    Verify the direction that the point
  _e_ is in relation to the vector
  formed by the points a->b
  -1 = right
  0 = collinear
  1 = left
 */
int ccw(point a, point b, point e) {
  int tmp = (b - a) ^ (e - a);
  return (tmp > 0) - (tmp < 0);
}

/*
  Verify if the point e
  is inside the triangle formed by
  the points t1, t2, t3
 */
bool inside_triangle(point t1, point t2, point t3,
                     point e) {
  int x = ccw(t1, t2, e);
  int y = ccw(t2, t3, e);
  int z = ccw(t3, t1, e);
  return !((x == 1 or y == 1 or z == 1) and
           (x == -1 or y == -1 or z == -1));
}
