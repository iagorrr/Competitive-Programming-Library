/*8<
  @Description: Computes the angle apb in radians
  @Warning: $a$ is equal to $b$ then the angle isn't defined.
>8*/
#include "./template.cpp"
template <typename T>
ld angle(const Point<T>& p, const Point<T>& a, const Point<T>& b) {
    auto ux = p.x - a.x;
    auto uy = p.y - a.y;

    auto vx = p.x - b.x;
    auto vy = p.y - b.y;

    auto num = ux * vx + uy * vy;
    auto den = hypot(ux, uy) * hypot(vx, vy);

    return acos(num / den);
}
