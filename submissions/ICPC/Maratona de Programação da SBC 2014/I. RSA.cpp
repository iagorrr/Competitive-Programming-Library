#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, E, C;

ll inv(ll a, ll b) {
  return a > 1 ? b - inv(b % a, a) * b / a : 1;
}

map<ll, ll> facts(ll n) {
  map<ll, ll> ans;
  for (ll i = 2; i * i <= n; i++) {
    ll count = 0;
    for (; n % i == 0; count++, n /= i)
      ;
    if (count) ans[i] = count;
  }
  if (n > 1) ans[n]++;
  return ans;
}

ll fpow(ll x, ll y, ll m) {
  ll ret = 1;
  while (y) {
    if (y & 1) ret = (ret * x) % m;
    y >>= 1;
    x = (x * x) % m;
  }
  return ret;
}

ll phi(ll n) {
  if (n == 1) return 1;

  auto fs = facts(n);
  auto res = n;
  for (auto [p, k] : fs) {
    res /= p;
    res *= (p - 1);
  }
  return res;
}

int main() {
  cin >> N >> E >> C;

  ll D = inv(E, phi(N));
  ll m = fpow(C, D, N);
  cout << m << endl;
}

/*
 * AC
 * Math
 * Number Theory
 * Phi function
 * */
