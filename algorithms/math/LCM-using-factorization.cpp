ll lcm_with_factorization(ll a, ll b) {
  map<ll, ll> fa = factorization(a);
  map<ll, ll> fb = factorization(b);
  ll ans = 1;
  for (auto fai : fa) {
    ll k = max(fai.second, fb[fai.first]);
    while (k--) ans *= fai.first;
  }
  return ans;
}
