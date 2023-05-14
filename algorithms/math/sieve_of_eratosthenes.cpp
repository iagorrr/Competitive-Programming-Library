#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll maxv = 1e5+1;
vector<char> isprime(maxv+1, true);
void sieve(){
  isprime[0] = isprime[1] = false;
  for(ll i = 2; i <= maxv; ++i) {
    if(isprime[i])
      for(ll j = i*i; j <= maxv; j += i)
        isprime[j] = false;
  }
}
