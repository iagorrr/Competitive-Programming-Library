#include "./template.cpp"
template <typename T>

T distance(const Point<T>& p, const Point<T>& q) {
    return hypot(p.x - q.x, p.y - q.y);
}
