template <typename T1, typename T2>
constexpr typename std::common_type<T1, T2>::type floor_div(T1 x, T2 y) {
    assert(y != 0);
    if (y < 0) x = -x, y = -y;
    return x < 0 ? (x - y + 1) / y : x / y;
}
