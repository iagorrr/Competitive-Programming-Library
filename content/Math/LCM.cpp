ll gcd(ll a, ll b) {
  return b ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
