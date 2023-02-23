/*
  iagorrr ;)
  Fast power agorithm to compute a^n in O(log(n))
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fastpow(ll a, int n){
  if (n==1) return a;
  ll x = fastpow(a, n/2);
  return x*x*(n&1?a:1);
}
int main(){
  cout << fastpow(2, 21) << '\n';
}
