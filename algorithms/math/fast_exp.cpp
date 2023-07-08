/*
  iagorrr ;)
  Fast exponentiation algorithm to compute a^n in O(log(n))
*/
ll fexp(ll a, int n){
        if(n == 0) return 1;
        if (n==1) return a;
        ll x = fexp(a, n/2);
        return x*x*(n&1?a:1);
}
