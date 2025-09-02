/*
rotate a point in the counter-clockwise
*/
#include "./template.cpp"
template<typename T>
Point<T> rotate(const Point<T>& P, T angle) {
    auto x = cos(angle) * P.x - sin(angle) * P.y;
    auto y = sin(angle) * P.x + cos(angle) * P.y;
    return { x, y };
}
