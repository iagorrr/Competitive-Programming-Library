ll inv(ll a, ll m) { return a > 1ll ? m - inv(m % a, a) * m / a : 1ll; }
