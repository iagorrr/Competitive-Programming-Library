template <auto cmp = greater<ll>()>
ll ternarySearch(ll l, ll r, auto f) {
  const ll eps = 3;
  while (r - l >= eps) {
    ll m1 = l + (r - l) / 3;
    ll m2 = r - (r - l) / 3;
    if (cmp(f(m1), f(m2)))
      r = m2;
    else
      l = m1;
  }
  for (ll i = l; i <= r; i++)
    if (cmp(f(i), f(l))) l = i;
  return l;
}

template <auto cmp = greater<ld>()>
ld ternarySearch(ld l, ld r, auto f, const ld eps = 1e-9) {
  while (r - l >= eps) {
    ld m1 = l + (r - l) / 3;
    ld m2 = r - (r - l) / 3;
    if (cmp(f(m1), f(m2)))
      r = m2;
    else
      l = m1;
  }
  return l;
}
}
