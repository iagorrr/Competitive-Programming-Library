/*8<
  @Title: Fast Pow
  @Description: Computes $a^b \pmod{m}$
  @Time: $O(\log{B})$.
>8*/
ll fpow(ll a, ll b, ll m) {
  ll ret = 1;
  while (b) {
    if (b & 1) ret = (ret * a) % m;
    b >>= 1;
    a = (a * a) % m;
  }
  return ret;
}
