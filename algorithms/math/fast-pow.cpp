ll fpow(ll a, ll b, ll m) {
  ll ret = 1;
  while (b) {
    if (b & 1) ret = (ret * a) % m;
    b >>= 1;
    a = (a * a) % m;
  }
  return ret;
}

ll fpow(ll a, ll b, ll m) {
  if (!b) return 1;
  ll ans = fpow2((a * a) % m, b / 2ll, m);
  return b & 1 ? (a * ans) % m : ans;
}
