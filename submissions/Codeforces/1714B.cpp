// iagorrr ;) O(N)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(vector <ll> a, ll N){
    map<ll, bool> m;
    ll ans = 0;
    // Looking backwards remove find the prefix when find the first number to repeat.
    for(ll i = N-1; i > -1; --i){
        if(m[a[i]]) return N-ans;

        ans++;
        m[a[i]] = true;
    }

    return N-ans;
}
int main(){
    ll T;
    cin >> T;

    while(T--){
        ll N;
        cin >> N;
        vector<ll> a(N);

        ll i = -1;
        while(++i < N) cin >> a[i];

        cout << solve(a, N) << endl;
    }
    return 0;
}

// Accepted.