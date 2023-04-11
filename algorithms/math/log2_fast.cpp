#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#if __cplusplus >= 202002
int flog2(unsigned long x) {
  ull i = x; 
  return std::bit_width(i) - 1;
}
#else
int flog2(ll x) {
  ull i = x;
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}
#endif

int main(){
  ll a = 123903210981;
  cout << log2(a) << ' ' << flog2(a) << '\n';
}

