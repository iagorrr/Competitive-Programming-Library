// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isprime(ll n) {// O(sqrt(n))
  if (n < 2)
    return false;
  if (n == 2)
    return true;
  if (n % 2 == 0)
    return false;
  for (ll i = 3; i * i < n; i += 2)
    if (n % i == 0)
      return false;
  return true;
}
int main() {}
