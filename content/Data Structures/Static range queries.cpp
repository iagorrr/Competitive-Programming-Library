template <typename T = ll,
          auto op =
              [](const T &src1, const T &src2,
                 T &dst) { dst = src1 + src2; },
          auto invop =
              [](const T &src1, const T &src2,
                 T &dst) { dst = src1 - src2; }>
struct StaticRangeQueries {
  vector<T> acc;
  StaticRangeQueries(const vector<T> &XS)
      : acc(len(XS)) {
    acc[0] = XS[0];
    rep(i, 1, len(XS)) {
      op(acc[i - 1], XS[i], acc[i]);
    }
  }
  T operator()(int l, int r) {
    T lv = (l ? acc[l - 1] : T());
    T ret;
    invop(acc[r], lv, ret);
    return ret;
  }
};
