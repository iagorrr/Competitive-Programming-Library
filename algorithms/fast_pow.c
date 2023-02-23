/*
  iagorrr ;)
  Fast power agorithm to compute a^n in O(log(n))
*/
#include <stdio.h>
#define ll long long

ll fastpow(ll a, int n){
  if (n==1) return a;
  ll x = fastpow(a, n/2);
  return x*x*(n&1?a:1);
}
int main(){
  printf("%lli\n", fastpow(2, 21));
}
