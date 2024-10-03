// Basic point/vector struct.
template<typename T>
struct Point {
    T x, y;
    Point(T  x = 0, T y = 0) : x(x), y(y) {}

    // Addition, substraction, multiply by constant, dot product, cross product.

    friend Point<T> operator + (const Point<T>& p, const Point<T>& q) {
        return Point<T>(p.x + q.x, p.y + q.y);
    }

    friend Point<T> operator - (const Point<T>& p, const Point<T>& q) {
        return Point<T>(p.x - q.x, p.y - q.y);
    }

	template<typename T2>
    friend Point<T> operator * (const Point<T>& p, T2 k) {
        return Point<T>(p.x * k, p.y * k);
    }

    friend T dot(const Point<T>& p, const Point<T>& q) {
        return p.x * q.x + p.y * q.y;
    }

    friend T cross(const Point<T>& p, const Point<T>& q) {
        return p.x * q.y - p.y * q.x;
    }
};
