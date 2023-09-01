template<typename T>
struct Point{
    T x, y;
    Point(T vx = 0, T vy = 0): x(vx), y(vy) {};

    double distTo (const Point<T> &p);

    bool operator==(const Point<T> &p) const;

    bool operator!=(const Point<T> &p) const;

    Point<T> operator+ (const Point<T> &p) const;

    Point<T> operator- (const Point<T> &p) const;
};

template<typename T>
double Point<T>::distTo (const Point<T> &p){
    return hypot(x - p.x, y - p.y);
}

template<typename T>
bool Point<T>::operator==(const Point<T> &p) const {
return equals(x, p.x) and equals(y, p.y);
}

template<typename T>
bool Point<T>::operator!=(const Point<T> &p) const {
return not (*this == p);
}

template<typename T>
Point<T> Point<T>::operator+ (const Point<T> &p) const {
    return {p.x + x, p.y + y};
}

template<typename T>
Point<T> Point<T>::operator- (const Point<T> &p) const {
    return {p.x - x, p.y - y};
}
