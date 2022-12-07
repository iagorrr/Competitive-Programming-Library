/*
 * iagorrr ;)
 * algorithm to find the perfect square of x usinb binary search, if didn't exist simpy returns 0.
 *
 */
#include <bits/stdc++.h>
using ll = long long;

ll square_bb_p(ll x){
    ll l = 0, r = x+1;

    while(l+1 < r){
        ll mid = l + (r-l)/2; // way to avoid overflow.

        if(mid*mid <= x) l = mid;
        else r = mid;
    }

    return l;
}

int main(){

    return 0;
}
