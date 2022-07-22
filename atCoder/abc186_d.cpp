// iagorrr
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll solve(vector <ll> v, ll N){
    /*
        X = total numbers after the one we want.
        v = the value that will be decreased;
        Y = the sum of every number after the v[i].

        in instead of make.

        |v - v[i+1]| + |v - v[i+2]| ... |v - v[N]|

        can view as :

        (v[i] * N-i) - (v[i+1] + v[i+2] ... v[N])

        and finally :

        (v[i] * X) - Y

        We can find Y by removing from the sum of EVERY element the sum until i.
    */
    sort(v.begin()+1, v.end()-1);

    // prefix sum though the vector.
    ll i = 0;
    while(++i <= N) v[i] += v[i-1];

    ll ans = 0;
    for(i = 1; i < N; ++i) ans += (v[N] - v[i]) - (v[i] - v[i-1])*(N-i);
    return ans;
}


int main(){
    ll N;
    cin >> N;

    vector<ll> v(N+2, 0);
    ll i = 1;
    while(i <= N) cin >> v[i++];


    cout << solve(v, N) << endl;
    return 0;
}

// Accepted.