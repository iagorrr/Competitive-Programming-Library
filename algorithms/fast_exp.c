/*
  iagorrr ;)
  Fast exponentiation algorithm to compute a^n in O(log(n))
*/
#include <stdio.h>
#define ll long long

ll fexp(ll a, int n){
  if (n==1) return a;
  ll x = fexp(a, n/2);
  return x*x*(n&1?a:1);
}
int main(){
  printf("%lli\n", fexp(2, 21));
}
