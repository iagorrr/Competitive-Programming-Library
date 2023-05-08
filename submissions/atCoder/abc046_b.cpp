// iagorrr
#include <bits/stdc++.h>
using namespace std;
using ll = long long;



ll solve(ll N, ll K){
    ll ans = K;
    for(int i = 1; i < N; ++i){
        ans*=(K-1);
    }

    return ans;
}

int main(){
    ll N, K;
    cin >> N >> K;

    cout << solve(N, K) << endl;
    return 0;
}

// AC
