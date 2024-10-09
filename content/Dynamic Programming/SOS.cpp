/*8<
  @Title: Sum of Subsets
  @Description:
    Allows you to find if some mask $X$ is a
    super mask of any of the given masks
  @Usage:
    Call $build$ with the $masks$ then it returns
    a vector of bool $V$ where $V_X$ says if $X$
    is a super mask of any of the initial maks

    You can change it to count how many submasks
    of each mask exsists, by changing the bitwise
    or by a plus sign...
  @Time: $O(LOG \cdot 2^{LOG})$
  @Memory: $O(LOG^2 \cdot 2^{LOG})$
  @Warning:
    Remember to set $LOG$ with the highest
    bit possible
>8*/
const int LOG = 20;
vc build(const vi &masks) {
  vc ret(1 << LOG);
  trav(mi, masks) ret[mi] = 1;
  rep(b, 0, LOG) {
    rep(mask, 0, (1 << LOG)) {
      if (mask & (1 << b)) ret[mask] |= ret[mask ^ (1 << b)];
    }
  }
  return ret;
}
