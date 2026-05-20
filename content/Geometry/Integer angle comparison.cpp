/*8<
  @Description:
    Integer angle comparison without floating-point arithmetic.

    Sorts points by polar angle around the origin using only integer operations.
    Points are first categorized into quadrants, then compared within each
    quadrant using cross products to avoid precision errors.

    Quadrant ordering:
    - c=1: x>0, y<0 (bottom-right)
    - c=2: x>=0, y=0 (positive x-axis)
    - c=3: x,y>0 or x<=0,y>0 (top half)
    - c=4: x<0, y=0 (negative x-axis)

    Within the same quadrant, angles are compared using the cross product:
    point A comes before point B if cross(A, B) = A.y*B.x - A.x*B.y < 0

    This is particularly useful for:
    - Angular sweep algorithms
    - Convex hull variants
    - Problems requiring exact angle comparisons
    - Avoiding floating-point precision issues
>8*/
struct pt {
    ll x, y, c;

    pt(ll _x, ll _y) : x(_x), y(_y) {
        if (y == 0) {
            c = x >= 0 ? 2 : 4;
        } else {
            c = y >= 0 ? 3 : 1;
        }
    }

    bool operator<(const pt& o) const {
        if (o.c == c) {
            return y * o.x < x * o.y;
        } else {
            return c < o.c;
        }
    }
};
